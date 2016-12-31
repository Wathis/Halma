#include "verifications.h"

//Fonction qui permet la verification d'une selection d'un pion. Elle renvoit 0 si celle si 
//est possible, sinon 1.
int verificationDeSelection(Plateau *plateau,Case *caseATester,int joueur){
    if (plateau->tab[caseATester->y ][caseATester->x ] != joueur + 48){
        afficherLePlateau(plateau);
        erreur("\tVous avez fait une mauvaise sélection, ce pion ne vous appartient pas");
        return 1;
    }
    return 0;
}

//Fonction qui renvoi 1 si la case est prise, et 0 si elle n'est pas prise
int testDeCase(Plateau *plateau,Case *caseATester){
    if (plateau->tab[caseATester->y ][caseATester->x ] != '0'){
        return 0;
    }
    else if (caseATester->x > 9 || caseATester->y > 9 || caseATester->x < 0 || caseATester->y < 0){
        return 0;
    }
    else {
        return 1;
    }
}

//Fonction qui permet de renvoyer e nombre de saut possible pour le joueur
int nbrSautPossible(Plateau *plateau,Case caseSelectionne){
    int nbrDeSautsPossibles = 0;
    Case casePossible;
    for (int i = 0 ; i <= 9 ; i++){
        for (int j = 0 ; j <= 9 ;j++){
            casePossible.y = i;
            casePossible.x = j;
            double distanceEntreDeuxPions = sqrt(pow((caseSelectionne.x - casePossible.x),2) + pow((caseSelectionne.y - casePossible.y),2));
            if (((distanceEntreDeuxPions == sqrt(8) || distanceEntreDeuxPions == 2 )) && testDeCase(plateau,&casePossible)){
                Case caseSaute;
                caseSaute.x = (caseSelectionne.x+casePossible.x)/2;
                caseSaute.y = (caseSelectionne.y+casePossible.y)/2;  
                if(plateau->tab[caseSaute.y][caseSaute.x]  == 50 || plateau->tab[caseSaute.y ][caseSaute.x ] == 49)
                {
                    nbrDeSautsPossibles++;
                }
            }
        }
    }
    return nbrDeSautsPossibles;

}

//Fonction qui verifie la possibilité de déplacement d'un pion, retourne 1 si le joueur peut se deplacer
int verificationDeDeplacement(Plateau *plateau,Case caseSelectionne,Case caseDeplacement,int typeVerification){
    //cette variable contient la distance entre deux cases, pour verifier si le joueur peut se deplacer  
    double distanceEntreDeuxPions = sqrt(pow((caseSelectionne.x - caseDeplacement.x),2) + pow((caseSelectionne.y - caseDeplacement.y),2));
    //Si la case n'est pas prise : 
    if (testDeCase(plateau,&caseDeplacement)){    
        if (typeVerification == 1){ // Si le type de verification est 1 , on doit verifier les déplacements simples
                //Alors
                //Premiere vérification de déplacement simple
                if (distanceEntreDeuxPions <= sqrt(2)){
                    return 1;
                }
        }
        //Deuxieme vérification de saut
        if ((distanceEntreDeuxPions == sqrt(8) || distanceEntreDeuxPions == 2 )){
            Case caseSaute;
            caseSaute.x = (caseSelectionne.x+caseDeplacement.x)/2;
            caseSaute.y = (caseSelectionne.y+caseDeplacement.y)/2;  
            if(plateau->tab[caseSaute.y][caseSaute.x]  == 50 || plateau->tab[caseSaute.y ][caseSaute.x ] == 49)
            {
                return 1;
            }
        }
    }
    return 0;
}

//Fonction qui indique les possibilités de déplacement
//nous faisons une copie du tableau pour éviter de modifier les cases du vrai plateau
//le type 1 est le type d'indication de la premiere fois qu'il joue, et 2 de la possibilité de rejouer
int indicationDeDeplacement(Plateau plateau,Case caseSelectionne,int typeIndication){
    //On test toutes les cases possibles du plateau, grace a verificationDeDeplacement
    Case casePossible;
    for (int i = 0 ; i <= 9 ; i++){
        for (int j = 0 ; j <= 9 ;j++){
            casePossible.y = i;
            casePossible.x = j;
            if (verificationDeDeplacement(&plateau,caseSelectionne,casePossible,1) && typeIndication == 1){
                //Le * indique une possibilié de déplacement pour le joueur
                plateau.tab[i][j] = '*';
            }
            if (verificationDeDeplacement(&plateau,caseSelectionne,casePossible,2) && typeIndication == 2){
                //Le * indique une possibilié de déplacement pour le joueur
                plateau.tab[i][j] = '*';
            }
        }
    }
    //On affiche le plateau (copié)
    afficherLePlateau(&plateau);
    return 0;
}

//Fonction qui verifie si un joueur a gagné 
int verificationDeWin(Plateau *plateau,int joueur){

    int nbrDePions = 0;

    //Vérification en haut à gauche
    if (joueur == 2){
        for (int i = 0 ; i < 5 ; i++){
            for (int j = 4 - i; j >= 0 ; j--){
                if (plateau->tab[i][j] == joueur + 48){
                    nbrDePions++;
                }
            }
        }
    }

    //Vérification en bas à droite 
    if (joueur == 1){
        int v = 0;
        for (int i = 5 ; i <= 9 ; i++){
            for (int j = 9 - v; j <= 9 ; j++){
                if (plateau->tab[i][j] == joueur + 48){
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













