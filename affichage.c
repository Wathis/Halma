#include "affichage.h"
//Fonction qui affiche le tableau a un moment : t

void afficherLePlateau(Plateau *plateau){
	//On récupere le joueur qui joue
    extern int joueur;
    //On efface l'écran
    system("clear");
    //On fait des tabulations
    printf("\t\t      ");
    //Placement des numéros du dessus
    for (int i = 0;i <= 9;i++){
        printf(COLOR_JAUNE "%d   " COLOR_RESET,i);
    }
    //Placement des barres du dessus 
    printf("\n\n\t\t      ");
    for (int i = 0;i <= 9;i++){
        printf(COLOR_JAUNE "|   " COLOR_RESET);
    }
    //Placement de la premiere lettre
    printf(COLOR_JAUNE "\n\n\t\tA  -  " COLOR_RESET);
    //Boucle des lignes
    for (int i = 0 ; i < TAILLE ; i++){
    	//Boucle au niveau des colonnes
        for (int j = 0 ; j < TAILLE ; j++){
        	//Si la case est 0, mettre 0 en blanc
            if (plateau->tab[i][j] == '0'){
                printf(COLOR_BLANC "%c   " COLOR_RESET,' ');
            }
            //Sinon si la case est 1 mettre en cyan
            else if (plateau->tab[i][j] == '1'){
                printf(COLOR_CYAN "%c   " COLOR_RESET,'X');
            }
            //Sinon si la case est 2 mettre en rouge
            else if (plateau->tab[i][j] == '2'){
                printf(COLOR_ROUGE "%c   " COLOR_RESET,'O');
            }
            //Sinon si la case est A mettre en cyan et clignoter ( Veut dire que c'est la séléction du joueur )
            else if (plateau->tab[i][j] == 'A'){  //A est pour la séction du joueur 1
            	plateau->tab[i][j] = joueur + 48;
                printf(COLOR_CYAN FAIRE_CLIGNOTER "%c   " COLOR_RESET,'X');
            }
            //Sinon si la case est B mettre en rouge et clignoter ( Veut dire que c'est la séléction du joueur )
            else if (plateau->tab[i][j] == 'B'){ //B pour la séléction du joueur 2
            	plateau->tab[i][j] = joueur + 48;
                printf(COLOR_ROUGE FAIRE_CLIGNOTER "%c   " COLOR_RESET,'O');
            }
            //Sinon si la case est * mettre en vert ( possibilités )
            else if (plateau->tab[i][j] == '*'){ //pour les possibilités
                printf(COLOR_VERT "%c   " COLOR_RESET,plateau->tab[i][j]);
            }
            //Sinon si mettre la case en couleur par default
            else {
                printf("%c   ",plateau->tab[i][j]);
            }
        }
        //Evite de mettre en trop le "I - "
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
    printf("\t\t Rappel ! X = Joueur 1 et O = Joueur 2");
    printf("\n\n\t 1 : Nouvelle partie");
    printf("\n\t 2 : Charger une partie");
    printf("\n\n\t Choix : ");        
}

void afficherLesParties(char **parties,int tailleTab){  
	int i = 0;
	system("clear");
	printf("\t  ###############################################################\n");
    printf("\t  #                                                             #\n");
    printf("\t  #                       Voici les parties                     #\n");
    printf("\t  #                                                             #\n");
    printf("\t  ###############################################################\n\n\n");
	while(*parties[i] != '0'){ //Le / est la fin de la liste des parties 
		printf("\t\t\t\t %d : %s\n",i + 1,parties[i]);
		i++;
	}
}

//Fonction pour afficher une erreur
void erreur(char Message[]){
    printf("%s",Message);
}
