#define TAILLE 10
#include <stdio.h>
#include <stdlib.h>
int joueur;

//Fonction qui rempli le plateau de 0

void initialiserTableau(int taille[TAILLE][TAILLE]);

//Fonction qui positionne les joueurs

void positionnerLesPions(int plateau[TAILLE][TAILLE],int x,int y,int joueur);

//Fonction qui affiche le tableau a un moment : t

void afficherUnTableau(int tableau[TAILLE][TAILLE]);

//Fonction qui initialise tout

void initialisation(int plateau[TAILLE][TAILLE],int x1,int x2,int y1,int y2,int joueur1,int joueur2);
