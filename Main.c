#include <stdio.h>
#include <stdlib.h>
#include "Mouvements.h"
#include "Initialisation.h"
#include "Affichage.h"

#define TAILLE 10

int main (void){

    //Déclarations des variables
    int plateauDeJeu[TAILLE][TAILLE],quitter = 0,quitterPartie = 0,quitterMenu = 0,xSelectionne,ySelectionne,nbDeJoueurs;
    
    do { //Boucle principale du jeu
        
        do { //Boucle du menu
            afficherLeMessageDuMenu();
            nbDeJoueurs = 2;
            quitterMenu = 1;
        } while (quitterMenu != 1);
        
        //Initialisation du jeu
        initialisation(plateauDeJeu,0,9,0,9,1,2);
        
        do { //Boucle de la partie en cours
        
            selectionnerUnPion(&xSelectionne,&ySelectionne,joueur);
            deplacerUnPion(xSelectionne,ySelectionne,plateauDeJeu);
            
            if (joueur < nbDeJoueurs)
                joueur++;
            else 
                joueur = 1;
            
        }while (quitterPartie != 1);
        
        
    }while (demandeNouvellePartie());
    
    system("clear");
    return 0;
}
