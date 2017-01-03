#include "sauvegarde.h"
#define TAILLE 10

int main (void){

    //Déclarations des variables
    int quitterPartie = 0,choix = 0,nbDeJoueurs,partieChoisie;
    Plateau plateauDeJeu;
    Case caseOriginJoueur1,caseOriginJoueur2;

    //Plateau *plateau,Case originJoueur1,Case originJouer2,int joueur1,int joueur2);

    do { //Boucle principale du jeu
        quitterPartie = 0;
        do { //Boucle du menu
            afficherLeMessageDuMenu();
            nbDeJoueurs = 2;
            scanf("%d", &choix);
        } while (choix != 1 && choix != 2);
        
        //Initialisation du jeu
    	if(choix == 1)
    	{
            initialisation(&plateauDeJeu,&caseOriginJoueur1,&caseOriginJoueur2,1,2);
    	}
    	else if(choix == 2){
    		char *parties[10] = {"Partie 1","Partie 2","Partie 3","Partie 4","Partie 5","0"};
    		afficherLesParties(parties,10);
            scanf("%d",&partieChoisie);
    		chargerSauvegarde(&plateauDeJeu,parties[partieChoisie - 1]);
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
