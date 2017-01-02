#include "mouvements.h"

//Fonction pour déplacer un pion
int deplacerUnPion(Plateau *plateau){ //x et y sont les coordonnées où déplacer
    
    //On récupère le joueur à déplacer
    extern int joueur;
    int nbrDeSautPossible = 0,nbrDeCoupsJoue = 0;
    char veutRejouer = 'N';
    int verification = 1,verificationSelection = 1;
    Case caseSelectionne,caseDeplacement;

    //Boucle de séléction principale ( Pour éviter que l'utilisateur se trompe ou donne une mauvaise case)
    do {
        do {//Boucle de séléction d'un pion

            if (nbrDeCoupsJoue == 0){
                do { //Premiere boucle pour voir si la séléction est correcte 
                    if (faireUneSaisie(&caseSelectionne,joueur,0) != 0){
                    	return 1;
                    }
                    //Le -1 sert de repert pour afficherLePlateau, pour savoir quel pion doit clignoter
                    verificationSelection = verificationDeSelection(plateau,&caseSelectionne,joueur);
                    //plateau->tab[caseSelectionne.y][caseSelectionne.x] = -joueur;
                }while (verificationSelection);
            }else if (verification != 0){
                caseSelectionne.x = caseDeplacement.x;
                caseSelectionne.y = caseDeplacement.y;
            }

            //Permet d'indiquer a l'algorithme quel pion doit clignoter ( voir affichage.c )
            if (joueur == 1){
            	plateau->tab[caseSelectionne.y][caseSelectionne.x] = 'A';
        	}else {
        		plateau->tab[caseSelectionne.y][caseSelectionne.x] = 'B';
        	}

        	//Afficher les déplacements possibles
            if (nbrDeCoupsJoue == 0){
                indicationDeDeplacement(*plateau,caseSelectionne,1);
            }
            else {
                indicationDeDeplacement(*plateau,caseSelectionne,2);
            }
            //Conversion en ACSII du joueur
            plateau->tab[caseSelectionne.y][caseSelectionne.x] = joueur + 48;
            //On lui demande les coordonées où il veut aller
            faireUneSaisie(&caseDeplacement,joueur,1);
            nbrDeSautPossible = nbrSautPossible(plateau,caseDeplacement);
            //On associe a verification la valeur retournée de verification ( Utile car on modifie plateau->tab après)
            if (nbrDeCoupsJoue == 0){ 
            	//Premier type de verification qui verifie les coups simple et doucle 
                verification = verificationDeDeplacement(plateau,caseSelectionne,caseDeplacement,1);
            }
            else {
            	//Deuxieme type qui verifie uniquement pour les coups double ( car c'est un combo comme nbrDeCoupsJoue > 0)
                verification = verificationDeDeplacement(plateau,caseSelectionne,caseDeplacement,2);
            }
            //Ici il y aura la vérification 
            if (verification != 0){
                //On déplace le joueur 
                plateau->tab[caseSelectionne.y][caseSelectionne.x] = '0';
                plateau->tab[caseDeplacement.y][caseDeplacement.x] = joueur + 48;
                afficherLePlateau(plateau);
                nbrDeCoupsJoue++;
            }else {
                afficherLePlateau(plateau);
                erreur("\t   Vous n'avez pas le droit de faire ce déplacement  \n");
            }

        }while(verification == 0);

        if (nbrDeSautPossible != 0 && verification == 2){ //verification=2 veut dire que le coup d'avant est un saut
            while(getchar() != '\n');
            printf("\n\t\t  Vous pouvez rejouer avec le même pion, voulez vous le faire ? O / N :");
            scanf("%c",&veutRejouer);
        }
    }while(nbrDeSautPossible != 0 && veutRejouer == 'O');

    return 0;
}
