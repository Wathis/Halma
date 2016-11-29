#include "saisie.h"

//Fonction qui demande si les utilisateurs veulent refaire une partie
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

//Fonction pour séléctionner un pion
void selectionnerUnPion(Case *caseSelectionne,int joueur){ //Coordonnées du pion séléctionné

	printf("\n\t   Joueur %d (Selectionnez la coordonnée x de votre pion) :",joueur);
    scanf("%d",&(caseSelectionne->x));
    printf("\n\t   Joueur %d (Selectionnez la coordonnée y de votre pion) :",joueur);
    scanf("%d",&(caseSelectionne->y));

}

//Fonction pour séléctonner une case pour le déplacement
void selectionnerUneCaseDeplacement(Case *caseSelectionne,int joueur){ //Coordonnées du pion séléctionné

    printf("\n\t   Joueur %d (Selectionnez la coordonnée x de la case de déstination) :",joueur);
    scanf("%d",&(caseSelectionne->x));
    printf("\n\t   Joueur %d (Selectionnez la coordonnée y de la case de déstination) :",joueur);
    scanf("%d",&(caseSelectionne->y));

}