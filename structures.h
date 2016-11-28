#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE 10

typedef struct Joueur Joueur;
typedef struct Plateau Plateau;
typedef struct Case Case;

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
