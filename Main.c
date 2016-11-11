#include <stdio.h>
#include <stdlib.h>
#include "Mouvements.h"
#include "Initialisation.h"
#define TAILLE 10

int main (void){

    //Déclarations des variables
    int plateauDeJeu[TAILLE][TAILLE],quitter = 0,quitterPartie = 0,quitterMenu = 0,xSelectionne,ySelectionne,nbDeJoueurs;
    
    do { //Boucle principale du jeu
        
        do { //Boucle du menu
            
            //Effacer l'ecran
            system("clear");
    
            printf("\t  ###############################################################\n");
            printf("\t  #                                                             #\n");
            printf("\t  #                       JEU DU HALMA                          #\n");
            printf("\t  #                                                             #\n");
            printf("\t  ###############################################################\n\n\n");
            
            nbDeJoueurs = 2;
            quitterMenu = 1;
            
        } while (quitterMenu != 1);
        
        //Initialisation du jeu
        joueur = 1; //Déclaré dans le initialisation.h
        initialisation(plateauDeJeu,0,9,0,9,1,2);
        
        do { //Boucle de la partie en cours
            
            
            selectionnerUnPion(&xSelectionne,&ySelectionne,joueur);
            deplacerUnPion(xSelectionne,ySelectionne,plateauDeJeu);

            if (joueur < nbDeJoueurs)
                joueur++;
            else 
                joueur = 1;
            
        
        }while (quitterPartie != 1);
        
        system("clear");
        printf("Voulez-vous quitter le jeu ? ( 1 = Oui / 2 = Non ) ");
        scanf("%d",&quitter);
        
    }while (quitter != 1);
    
    system("clear");
    return 0;
}
