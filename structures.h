#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

#define TAILLE 10

typedef struct Joueur Joueur;
typedef struct Plateau Plateau;
typedef struct Case Case;

int joueur; //Joueur est une variable globale car nous en avons besoin partout et c'est la même pour tous fichiers

//La structure joueur est la structure d'un joueur, avec ses differentes caracteristiques
struct Joueur{
    char nom[30];
    int chiffre;
    int niveau;
    char couleur;
};

//La structure plateau est le plateau de jeu
struct Plateau{
	int joueurQuiJoue;
    char tab[TAILLE][TAILLE];
};

//La structure Case est une structure pour representer une case du plateau
struct Case{
    int x;
    int y;
};
