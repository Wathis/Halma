#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define TAILLE 10

typedef struct Joueur Joueur;
typedef struct Plateau Plateau;
typedef struct Case Case;

int joueur; //Joueur est une variable globale car nous en avons besoin partout et c'est la même pour tous fichiers

struct Joueur{
    char nom[30];
    int chiffre;
    int niveau;
    char couleur;
};

struct Plateau{
    int tab[TAILLE][TAILLE];
};

struct Case{
    int x;
    int y;
};
