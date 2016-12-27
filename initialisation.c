#include "initialisation.h"
//Fonction qui rempli le plateau de 0
void initialiserPlateau(Plateau *plateau){
    for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
            plateau->tab[i][j] = (char) 48; //48 vaut 0 en ACSII
        }
    }
}

//Fonction qui positionne les joueurs

void positionnerLesPions(Plateau *plateau,Case *origin,int joueur){ //Avec x et y points de départ du joueur
    
    //Depuis en haut a gauche
    //La case origin est la case d'origine où l'algorithme doit placer les pions
    if ( origin->x == 0 && origin->y == 0){
        for (int i = 0 ; i < 5 ; i++){
            for (int j = 4 - i; j >= 0 ; j--){
                plateau->tab[i][j] = (char) (joueur + 48);
            }
        }
    }
    
    //depuis en bas a droite
    if ( origin->x == 9 && origin->y == 9 ){
        int v = 0;
        for (int i = 5 ; i <= 9 ; i++){
            for (int j = 9 - v; j <= 9 ; j++){
                plateau->tab[i][j] = (char) (joueur + 48);
            }
            v++;
        }
    }

}

//Fonction qui initialise tout

void initialisation(Plateau *plateau,Case *originJoueur1,Case *originJoueur2,int joueur1,int joueur2){

    //Initialisation des differentes cases d'origine des joueurs
    originJoueur1->x = 0;
    originJoueur1->y = 0;
    originJoueur2->x = 9;
    originJoueur2->y = 9;

    initialiserPlateau(plateau);
    positionnerLesPions(plateau,originJoueur1,joueur1);
    positionnerLesPions(plateau,originJoueur2,joueur2);
    afficherLePlateau(plateau);    
   
    joueur = 1;
}
