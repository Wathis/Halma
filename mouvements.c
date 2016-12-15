#include "mouvements.h"

//Fonction pour déplacer un pion
int deplacerUnPion(Plateau *plateau){ //x et y sont les coordonnées où déplacer
    
    //On récupère le joueur à déplacer
    extern int joueur;
    int verification = 1,verificationSelection = 1;
    Case caseSelectionne,caseDeplacement;

    //Boucle de séléction principale ( Pour éviter que l'utilisateur se trompe ou donne une mauvaise case)

    do {

        //Boucle de séléction d'un pion
        do {
            faireUneSaisie(&caseSelectionne,joueur,0);
            //Le -1 sert de repert pour afficherLePlateau, pour savoir quel pion doit clignoter
            verificationSelection = verificationDeSelection(plateau,&caseSelectionne,joueur);
            // plateau->tab[caseSelectionne.y][caseSelectionne.x] = -joueur;
        }while (verificationSelection);
        if (joueur == 1){
        	plateau->tab[caseSelectionne.y][caseSelectionne.x] = 'A';
    	}else {
    		plateau->tab[caseSelectionne.y][caseSelectionne.x] = 'B';
    	}

        indicationDeDeplacement(*plateau,caseSelectionne);

        plateau->tab[caseSelectionne.y][caseSelectionne.x] = joueur + 48;
        //On lui demande les coordonées où il veut aller
        faireUneSaisie(&caseDeplacement,joueur,1);
        //On associe a verification la valeur retournée de verification ( Utilie car on modifie plateau->tab après)
        verification = verificationDeDeplacement(plateau,caseSelectionne,caseDeplacement);
        //Ici il y aura la vérification 
        if (verification){
            //On déplace le joueur 
            plateau->tab[caseSelectionne.y][caseSelectionne.x] = '0';
            plateau->tab[caseDeplacement.y][caseDeplacement.x] = joueur + 48;
            afficherLePlateau(plateau);
        }else {
            afficherLePlateau(plateau);
            erreur("\t   Vous n'avez pas le droit de faire ce déplacement");
        }

    }while(!(verification));

    return 0;
}
