#include "verifications.h"

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
            if(plateau->tab[caseSaute.y - 1][caseSaute.x- 1]  == 1 || plateau->tab[caseSaute.y - 1][caseSaute.x - 1] == 2)
            {
                return 1;
            }
        }
    }
    return 0;
}

//je fais une copie du tableau pour éviter de modifier les cases du tableau
int indicationDeDeplacement(Plateau plateau,Case caseSelectionne){

    Case casePossible;
    for (int i = 0 ; i <= 9 ; i++){
        for (int j = 0 ; j <= 9 ;j++){
            casePossible.y = i + 1;
            casePossible.x = j + 1;
            if (verificationDeDeplacement(&plateau,caseSelectionne,casePossible)){
                //Le 8 indique une possibilié de déplacement pour le joueur
                printf("casePossible : %d %d\n",casePossible.y,casePossible.x);
                plateau.tab[i][j] = 8;
            }
        }
    }
    afficherLePlateau(&plateau);
    return 0;
}

int verificationDeWin(Plateau *plateau,int joueur){

    int nbrDePions = 0;

    //Haut Gauche
    if (joueur == 2){
        for (int i = 0 ; i < 5 ; i++){
            for (int j = 4 - i; j >= 0 ; j--){
                if (plateau->tab[i][j] == joueur){
                    nbrDePions++;
                }
            }
        }
    }

    //Bas droite 
    if (joueur == 1){
        int v = 0;
        for (int i = 5 ; i <= 9 ; i++){
            for (int j = 9 - v; j <= 9 ; j++){
                if (plateau->tab[i][j] == joueur){
                    nbrDePions++;
                }
            }
            v++;
        }
    }
    
    if (nbrDePions == 15){
        return 1; //C'EST GAGNÉ
    }else {
         return 0;
    }
}













