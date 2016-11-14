#include "Affichage.h"

//Fonction qui affiche le tableau a un moment : t

void afficherLePlateau(int plateau[TAILLE][TAILLE]){
    system("clear");
    printf("\n\t\t\t");
    for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
            printf("%d   ",plateau[i][j]);
        }
        printf("\n\n\t\t\t");
    }
    printf("\n");
}

void afficherLeMessageDuMenu(){
	//Effacer l'ecran
    system("clear");

	printf("\t  ###############################################################\n");
    printf("\t  #                                                             #\n");
    printf("\t  #                       JEU DU HALMA                          #\n");
    printf("\t  #                                                             #\n");
    printf("\t  ###############################################################\n\n\n");        
}

void erreur(char Message[]){
	printf("%s",Message);
}