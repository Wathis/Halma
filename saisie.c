#include "saisie.h"

//Fonction qui demande si les utilisateurs veulent refaire une partie. 
//Renvoie 1 pour ne pas quitter et 0 pour veut quitter
int demandeNouvellePartie(){
	//Variable permettant de savoir si l'utilisateur veut quitter
	int quitter;
	do {
    	printf("\n\t\t    Voulez-vous quitter le jeu ? ( 1 = Oui / 2 = Non ) ");
    	scanf("%d",&quitter);
    }while (quitter != 1 && quitter != 2);
    if (quitter == 2){
    	return 1;
    }else {
    	return 0;
    }
}

//Fonction pour séléctionner un pion
int faireUneSaisie(Case *caseSelectionne,int joueur,int categorieDeSelection){ //Coordonnées du pion séléctionné
	//Stockage de la case séléctionné dans un tableau de 2 char 
	char caseSelectionneChar[2];
	//Variavle pour stocker la vérification de saisie
	int saisieCorrecte = 1;
	//Variable d'échange
	char swap;
	do {//Premiere boucle générale de vérifiaction
		do {//Deuxieme boucle de vérification si l'utilisateur saisie plus que 2 caractères
			if (categorieDeSelection) {//0 -> selection de pion et 1 -> selection de déplacement
				printf("\n\t   Joueur %d : Selectionnez votre déstination :",joueur);
			}
			else {
				printf("\n\t   Joueur %d : Les selectionnez votre pion  :",joueur);
		    }
		    scanf("%s",caseSelectionneChar);
		    //Quitter si le caractere est Q 
		    if (caseSelectionneChar[0] == 'Q'){
		    	return 1;
		    }
		    if (strlen(caseSelectionneChar) != 2){
		    	printf("Votre saisie n'est pas correcte");
		    }
		}while(strlen(caseSelectionneChar) != 2);

		//Si le premier caractere est un nombre 
		if (caseSelectionneChar[0] >= 48 && caseSelectionneChar[0] <= 57){
			//Si le deuxieme caractere est une lettre
			if ((caseSelectionneChar[1] >= 65 && caseSelectionneChar[1] <= 72)||(caseSelectionneChar[1] >= 97 && caseSelectionneChar[1] <= 104)){
				//Alors on echange pour faire en sorte que l'algorithme ne traite que une lettre puis un chiffre
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

	return 0;
}









