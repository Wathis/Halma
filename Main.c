
#include <stdio.h>
#include <stdlib.h>
#include "Initialisation.h"
#define TAILLE 10

int main (void){
    
    //Déclaration des variables
    
    int plateauDeJeu[TAILLE][TAILLE],quitter = 0,quitterPartie = 0,quitterMenu = 0;
    
    do { //Boucle principale du jeu
        
        do { //Boucle du menu
            
            //Effacer l'ecran
            system("clear");
    
            printf("\t  ###############################################################\n");
            printf("\t  #                                                             #\n");
            printf("\t  #                       JEU DU HALMA                          #\n");
            printf("\t  #                                                             #\n");
            printf("\t  ###############################################################\n\n\n");
    
            quitterMenu = 1;
            
        } while (quitterMenu != 1);
        
        //Initialisation du jeu
        
        joueur = 1; //Déclaré dans le initialisation.h
        initialisation(plateauDeJeu,0,0,9,9,1,2);
        /*initialiserTableau(plateauDeJeu);
        positionnerLesPions(plateauDeJeu,0,0,1);
        positionnerLesPions(plateauDeJeu,9,9,2);
        afficherUnTableau(plateauDeJeu);*/
        
        do { //Boucle de la partie en cours
            
            
            
            printf("\n\t   Joueur %d ",joueur);
            scanf("%d",&quitterPartie);
            
            
        }while (quitterPartie != 1);
        
        system("clear");
        printf("Voulez-vous quitter le jeu ? ( 1 = Oui / 2 = Non ) ");
        scanf("%d",&quitter);
        
    }while (quitter != 1);
    
    system("clear");
    return 0;
}
