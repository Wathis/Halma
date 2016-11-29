#include "affichage.h"

int joueur;

//Fonction qui rempli le plateau de 0

void initialiserPlateau(Plateau *plateau);

//Fonction qui positionne les joueurs

void positionnerLesPions(Plateau *plateau,Case *origin,int joueur);

//Fonction qui initialise tout

void initialisation(Plateau *plateau,Case *originJoueur1,Case *originJouer2,int joueur1,int joueur2);
