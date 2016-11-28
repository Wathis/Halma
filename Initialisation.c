
#define TAILLE 10

#include "Initialisation.h"

//Fonction qui rempli le plateau de 0

void initialiserPlateau(int plateau[TAILLE][TAILLE]){
    for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
            plateau[i][j] = 0;
        }
    }
}

//Fonction qui positionne les joueurs

void positionnerLesPions(int plateau[TAILLE][TAILLE],int x,int y,int joueur){ //Avec x et y points de départ du joueur
    
    //Haut Gauche
    
    if ( x == 0 && y == 0){
        for (int i = 0 ; i < 5 ; i++){
            for (int j = 4 - i; j >= 0 ; j--){
                plateau[i][j] = joueur;
            }
        }
    }
    
    //Bas Droite
    
    if ( x == 9 && y == 9 ){
        int v = 0;
        for (int i = 5 ; i <= 9 ; i++){
            for (int j = 9 - v; j <= 9 ; j++){
                plateau[i][j] = joueur;
            }
            v++;
        }
    }

}

//Fonction qui initialise tout

void initialisation(int plateau[TAILLE][TAILLE],int x1,int x2,int y1,int y2,int joueur1,int joueur2){
    
    initialiserPlateau(plateau);
    positionnerLesPions(plateau,x1,y1,joueur1);
    positionnerLesPions(plateau,x2,y2,joueur2);
    afficherLePlateau(plateau);
    joueur = 1;
}
