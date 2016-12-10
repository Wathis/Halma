#include "saisie.h"

//Fonction qui demande si les utilisateurs veulent refaire une partie
int demandeNouvellePartie(){
	int quitter;
    printf("\t\t    Voulez-vous quitter le jeu ? ( 1 = Oui / 2 = Non ) ");
    scanf("%d",&quitter);
    if (quitter == 2){
    	return 1;
    }else {
    	return 0;
    }
}

//Fonction pour séléctionner un pion
void faireUneSaisie(Case *caseSelectionne,int joueur,int categorieDeSelection){ //Coordonnées du pion séléctionné
	char caseSelectionneChar[2];
	int saisieCorrecte = 1;
	do {
		do {
			if (categorieDeSelection) {//0 -> selection de pion et 1 -> selection de déplacement
				printf("\n\t   Joueur %d : Selectionnez votre déstination (LigneColonne) :",joueur);
			}
			else {
				printf("\n\t   Joueur %d : Les selectionnez votre pion (LigneColonne) :",joueur);
		    }
		    scanf("%s",caseSelectionneChar);
		    if (strlen(caseSelectionneChar) != 2){
		    	printf("Votre saisie n'est pas correcte, il faut choisir la ligne plus la colonne");
		    }
		}while(strlen(caseSelectionneChar) != 2);
		//Conversion des chars en int 
		caseSelectionne->y = caseSelectionneChar[0] - 65; //Moins 65 car le caractere A en ACSII vaut 65
		caseSelectionne->x = caseSelectionneChar[1] - 48; //Car en 48 on a le zéro en ACSII
		//Verification si les valeurs sont comprises dans le plateau
		if (caseSelectionne->x >= 0 && caseSelectionne->x <= 9 && caseSelectionne->y >= 0 && caseSelectionne->y <= 9){
			saisieCorrecte = 0;
		}else {
			printf("\n\t   Saisie incorecte");
		}

	}while(saisieCorrecte);

	printf("Saisie : %d %d\n",caseSelectionne->y,caseSelectionne->x);
}









