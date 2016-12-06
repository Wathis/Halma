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
            selectionnerUnPion(&caseSelectionne,joueur);
            //Le -1 sert de repert pour afficherLePlateau, pour savoir quel pion doit clignoter
            verificationSelection = verificationDeSelection(plateau,&caseSelectionne,joueur);
            plateau->tab[caseSelectionne.y - 1][caseSelectionne.x - 1] = -joueur;
        }while (verificationSelection);

        //Rafraichir l'écran de jeu
        afficherLePlateau(plateau);

        plateau->tab[caseSelectionne.y - 1][caseSelectionne.x - 1] = joueur;

        //On lui demande les coordonées où il veut aller
        selectionnerUneCaseDeplacement(&caseDeplacement,joueur);
        //On associe a verification la valeur retournée de verification ( Utilie car on modifie plateau->tab après)
        verification = verificationDeDeplacement(plateau,caseSelectionne,caseDeplacement);
        
        //Ici il y aura la vérification 
        if (verification){
            //On déplace le joueur 
            plateau->tab[caseSelectionne.y - 1][caseSelectionne.x - 1] = 0;
            plateau->tab[caseDeplacement.y - 1][caseDeplacement.x - 1] = joueur;
            afficherLePlateau(plateau);
        }else {
            afficherLePlateau(plateau);
            erreur("\t   Vous n'avez pas le droit de faire ce déplacement");
        }

    }while(!(verification));

    return 0;
}
/*
int verificationDeSelection(Plateau *plateau,Case *caseATester,int joueur){
    if (plateau->tab[caseATester->y - 1][caseATester->x - 1] != joueur){
        afficherLePlateau(plateau);
        erreur("\tVous avez fait une mauvaise sélection, ce pion ne vous appartient pas");
        return 1;
    }
    return 0;
}

//Fonction qui renvoi 1 si la case est prise, et 0 si elle n'est pas prise
int testDeCase(Plateau *plateau,Case *caseATester){
    if (plateau->tab[caseATester->y - 1][caseATester->x - 1] != 0){
        return 0;
    }
    else if (caseATester->x > 10 || caseATester->y > 10 || caseATester->x < 1 || caseATester->y < 1){
        return 0;
    }
    else {
        return 1;
    }
}

int verificationDeDeplacement(Plateau *plateau,Case caseSelectionne,Case caseDeplacement){
    double distanceEntreDeuxPions = sqrt(pow((caseSelectionne.x - caseDeplacement.x),2) + pow((caseSelectionne.y - caseDeplacement.y),2));
    if (testDeCase(plateau,&caseDeplacement)){
        //Premiere vérification de déplacement simple
        if (distanceEntreDeuxPions <= sqrt(2)){
            return 1;
        }
        //Deuxieme vérification de saut
        else if ((distanceEntreDeuxPions == sqrt(8) || distanceEntreDeuxPions == 2 )){
    	    Case caseSaute;
        	caseSaute.x = (caseSelectionne.x+caseDeplacement.x)/2;
    	    caseSaute.y = (caseSelectionne.y+caseDeplacement.y)/2;
            printf("%d %d",caseSaute.x,caseSaute.y);	    
            if(plateau->tab[caseSaute.y - 1][caseSaute.x- 1]  == 1 || plateau->tab[caseSaute.y - 1][caseSaute.x - 1] == 2)
    	    {
    	 	    return 1;
    	    }
        }
    }
    return 0;

}*/
