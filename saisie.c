#include "saisie.h"

//Fonction qui demande si les utilisateurs veulent refaire une partie
int demandeNouvellePartie(){
	int quitter;
    printf("\n\t\t    Voulez-vous quitter le jeu ? ( 1 = Oui / 2 = Non ) ");
    scanf("%d",&quitter);
    if (quitter == 2){
    	return 1;
    }else {
    	return 0;
    }
}

//Fonction pour séléctionner un pion
int faireUneSaisie(Case *caseSelectionne,int joueur,int categorieDeSelection){ //Coordonnées du pion séléctionné
	char caseSelectionneChar[2];
	int saisieCorrecte = 1;
	char swap;
	do {
		do {
			if (categorieDeSelection) {//0 -> selection de pion et 1 -> selection de déplacement
				printf("\n\t   Joueur %d : Selectionnez votre déstination :",joueur);
			}
			else {
				printf("\n\t   Joueur %d : Les selectionnez votre pion  :",joueur);
		    }
		    scanf("%s",caseSelectionneChar);
		    if (caseSelectionneChar[0] == 'Q'){
		    	return 1;
		    }
		    if (strlen(caseSelectionneChar) != 2){
		    	printf("Votre saisie n'est pas correcte");
		    }
		}while(strlen(caseSelectionneChar) != 2);
		if (caseSelectionneChar[0] >= 48 && caseSelectionneChar[0] <= 57){
			if ((caseSelectionneChar[1] >= 65 && caseSelectionneChar[1] <= 72)||(caseSelectionneChar[1] >= 97 && caseSelectionneChar[1] <= 104)){
				swap = caseSelectionneChar[0];
				caseSelectionneChar[0] = caseSelectionneChar[1];
				caseSelectionneChar[1] = swap;
			}
		}
		//Conversion des chars en int 
		if (caseSelectionneChar[0] >= 97 && caseSelectionneChar[0] <= 104){
			caseSelectionne->y = caseSelectionneChar[0] - 97; //Moins 97 car le caractere a en ACSII vaut 97
		}else {
			caseSelectionne->y = caseSelectionneChar[0] - 65; //Moins 65 car le caractere A en ACSII vaut 65
		}
		caseSelectionne->x = caseSelectionneChar[1] - 48; //Car en 48 on a le zéro en ACSII
		//Verification si les valeurs sont comprises dans le plateau
		if (caseSelectionne->x >= 0 && caseSelectionne->x <= 9 && caseSelectionne->y >= 0 && caseSelectionne->y <= 9){
			saisieCorrecte = 0;
		}else {
			printf("\n\t   Saisie incorecte");
		}

	}while(saisieCorrecte);

	printf("Saisie : %d %d\n",caseSelectionne->y,caseSelectionne->x);
	return 0;
}









