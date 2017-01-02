#include "sauvegarde.h"
#define TAILLE 10

int main (void){

    //Déclarations des variables
    int quitter = 0,quitterPartie = 0,quitterMenu = 0,nbDeJoueurs;
    Plateau plateauDeJeu;
    Case caseOriginJoueur1,caseOriginJoueur2;

    //Plateau *plateau,Case originJoueur1,Case originJouer2,int joueur1,int joueur2);

    do { //Boucle principale du jeu
        
        do { //Boucle du menu
            afficherLeMessageDuMenu();
            nbDeJoueurs = 2;
	    printf("\t 1 : Nouvelle partie\n\t 2 : Charger la partie en cours\n");
            scanf("%d", &quitterMenu);
	    
        } while (quitterMenu != 1 && quitterMenu != 2);
        
    //Initialisation du jeu
	if(quitterMenu == 1)
	{
        initialisation(&plateauDeJeu,&caseOriginJoueur1,&caseOriginJoueur2,1,2);
	}
	else if(quitterMenu == 2){
		chargerSauvegarde(&plateauDeJeu);
	}
	afficherLePlateau(&plateauDeJeu);
        do { //Boucle de la partie en cours
            if (deplacerUnPion(&plateauDeJeu) != 0){
            	quitterPartie = 1;
            }
            
            //Si la verificationDeWin renvoie 1 => alors on affiche le gagnant et quitte la partie
            if (verificationDeWin(&plateauDeJeu,joueur)){
                printf("\t\t    Joueur %d gagne\n",joueur);
                quitterPartie = 1;
            }
            //Si il ne faut pas quitter la partie => on change de joueur 
            if (quitterPartie != 1){
	            if (joueur < nbDeJoueurs){
	                joueur++;
	            }
	            else {
	                joueur = 1;
	            }
        	}
            sauvegarde(plateauDeJeu);
            
        }while (quitterPartie != 1);

    }while (demandeNouvellePartie());
    
    system("clear");
    return 0;
}
