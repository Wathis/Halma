#include "affichage.h"
//Fonction qui affiche le tableau a un moment : t

void afficherLePlateau(Plateau *plateau){
    extern int joueur;
    system("clear");
    printf("\t\t      ");
    for (int i = 0;i <= 9;i++){
        printf(COLOR_JAUNE "%d   " COLOR_RESET,i);
    }
    printf("\n\n\t\t      ");
    for (int i = 0;i <= 9;i++){

        printf(COLOR_JAUNE "|   " COLOR_RESET);
    }

    printf(COLOR_JAUNE "\n\n\t\tA  -  " COLOR_RESET);
    for (int i = 0 ; i < TAILLE ; i++){
        for (int j = 0 ; j < TAILLE ; j++){
            switch (plateau->tab[i][j]) {
                case 0: 
                    printf(COLOR_BLANC "%d   " COLOR_RESET,plateau->tab[i][j]);
                    break;
                case 1: 
                    printf(COLOR_CYAN "%d   " COLOR_RESET,plateau->tab[i][j]);
                    break;
                case 2: 
                    printf(COLOR_ROUGE "%d   " COLOR_RESET,plateau->tab[i][j]);
                    break;
                case -1: //Cas où il faut faire clignoter le joueur 1 sélectionné (Noté en -1 dans la matrice)
                    printf(COLOR_CYAN FAIRE_CLIGNOTER "%d   "  COLOR_RESET,joueur);
                    break;
                case -2://Cas où il faut faire clignoter le joueur 2 sélectionné (Noté en -2 dans la matrice)
                    printf(COLOR_ROUGE FAIRE_CLIGNOTER "%d   "  COLOR_RESET,joueur);
                    break;
                default:
                    printf("%d   ",plateau->tab[i][j]);
            }

        }
        if (i < TAILLE - 1){
            printf(COLOR_JAUNE "\n\n\t\t%c  -  " COLOR_RESET,i + 66);
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
