#include "affichage.h"
//Fonction qui affiche le tableau a un moment : t

void afficherLePlateau(Plateau *plateau){
    system("clear");
    printf("\t\t      ");
    for (int i = 1;i <= 10;i++){
        printf("%d   ",i);
    }
    printf("\n\n\t\t      ");
    for (int i = 1;i <= 10;i++){
        printf("|   ");
    }

    printf("\n\n\t\t1  -  ");
    for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
            printf("%d   ",plateau->tab[i][j]);
        }
        if (i < TAILLE - 1 && (i + 2) != 10){ //Pour éviter d'en avoir une en trop
            printf("\n\n\t\t%d  -  ",i + 2);
        }
        else if ((i + 2) == 10) {
            printf("\n\n\t       %d  -  ",i + 2);
        }
    }
    printf("\n\n");
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
