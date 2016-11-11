#include "Mouvements.h"

//Fonction pour déplacer un pion
int deplacerUnPion(int xSelectionne,int ySelectionne,int plateau[TAILLE][TAILLE]){ //x et y sont les coordonnées où déplacer

	//On récupère le joueur à déplacer
	int joueur = plateau[ySelectionne - 1][xSelectionne - 1],xDeplacement,yDeplacement;

	//Rafraichir l'écran de jeu
    system("clear");
    afficherLePlateau(plateau);

	//On lui demande les coordonées où il veut aller
	printf("\n\t   Joueur %d (Selectionnez la coordonnée x où déplacer le pion) :",joueur);
    scanf("%d",&xDeplacement);
    printf("\n\t   Joueur %d (Selectionnez la coordonnée y où déplacer le pion) :",joueur);
    scanf("%d",&yDeplacement);

    //Ici il y aura la vérification 

    //On déplace le joueur 
    plateau[ySelectionne - 1][xSelectionne - 1] = 0;
    plateau[yDeplacement - 1][xDeplacement - 1] = joueur;

    afficherLePlateau(plateau);

    return 0;
}

//Fonction pour séléctionner un pion
void selectionnerUnPion(int* xSelectionne,int* ySelectionne,int joueur){ //Coordonnées du pion séléctionné

	printf("\n\t   Joueur %d (Selectionnez la coordonnée x de votre pion) :",joueur);
    scanf("%d",xSelectionne);
    printf("\n\t   Joueur %d (Selectionnez la coordonnée y de votre pion) :",joueur);
    scanf("%d",ySelectionne);

}