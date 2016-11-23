#include "Saisie.h"

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
void selectionnerUnPion(int* xSelectionne,int* ySelectionne,int joueur){ //Coordonnées du pion séléctionné

	printf("\n\t   Joueur %d (Selectionnez la coordonnée x de votre pion) :",joueur);
    scanf("%d",xSelectionne);
    printf("\n\t   Joueur %d (Selectionnez la coordonnée y de votre pion) :",joueur);
    scanf("%d",ySelectionne);

}
