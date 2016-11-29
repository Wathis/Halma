#include "initialisation.h"
//Fonction qui rempli le plateau de 0

void initialiserPlateau(Plateau *plateau){
    for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
            plateau->tab[i][j] = 0;
        }
    }
}

//Fonction qui positionne les joueurs

void positionnerLesPions(Plateau *plateau,Case origin,int joueur){ //Avec x et y points de départ du joueur
    
    //Haut Gauche
    
    if ( origin.x == 0 && origin.y == 0){
        for (int i = 0 ; i < 5 ; i++){
            for (int j = 4 - i; j >= 0 ; j--){
                plateau->tab[i][j] = joueur;
            }
        }
    }
    
    //Bas Droite
    
    if ( origin.x == 9 && origin.y == 9 ){
        int v = 0;
        for (int i = 5 ; i <= 9 ; i++){
            for (int j = 9 - v; j <= 9 ; j++){
                plateau->tab[i][j] = joueur;
            }
            v++;
        }
    }

}

//Fonction qui initialise tout

void initialisation(Plateau *plateau,Case originJoueur1,Case originJoueur2,int joueur1,int joueur2){
    
    initialiserPlateau(plateau);
    positionnerLesPions(plateau,originJoueur1,joueur1);
    positionnerLesPions(plateau,originJoueur2,joueur2);
    afficherLePlateau(plateau);
    joueur = 1;
}
