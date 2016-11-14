#include "Saisie.h"

int demandeNouvellePartie(){
	int quitter;
	system("clear");
    printf("Voulez-vous quitter le jeu ? ( 1 = Oui / 2 = Non ) ");
    scanf("%d",&quitter);
    if (quitter == 2){
    	return 1;
    }else {
    	return 0;
    }
}