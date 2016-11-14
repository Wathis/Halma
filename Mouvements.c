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
    if (verificationDeDeplacement(plateau,xSelectionne,ySelectionne,xDeplacement,yDeplacement) == 1){
        //On déplace le joueur 
        plateau[ySelectionne - 1][xSelectionne - 1] = 0;
        plateau[yDeplacement - 1][xDeplacement - 1] = joueur;
        afficherLePlateau(plateau);
    }else {
        afficherLePlateau(plateau);
        erreur("\t   Vous n'avez pas le droit de faire ce déplacement");
    }
    return 0;
}

//Fonction qui renvoi 1 si la case est prise, et 0 si elle n'est pas prise
int testDeCase(int plateau[TAILLE][TAILLE],int x,int y){
    if (plateau[y][x] != 0){
        return 1;
    }
    else {
        return 0;
    }
}

int verificationDeDeplacement(int plateau[TAILLE][TAILLE],int xDepart,int yDepart,int xArrive,int yArrive){

    double distanceEntreDeuxPions = sqrt(pow((xDepart - xArrive),2) + pow((yDepart - yArrive),2));
    //Premiere vérification de déplacement simple
    if (distanceEntreDeuxPions <= sqrt(2)){
        return 1;
    }
    //Deuxieme vérification de saut
    else if (distanceEntreDeuxPions == sqrt(8) || distanceEntreDeuxPions == 2){
        return 1;
    }
    else{
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