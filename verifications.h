#include "saisie.h"

int verificationDeSelection(Plateau *plateau,Case *caseATester,int joueur);
int verificationDeDeplacement(Plateau *plateau,Case caseSelectionne,Case caseDeplacement);
int testDeCase(Plateau *plateau,Case *caseATester);
int verificationDeWin(Plateau *plateau,int joueur);
int indicationDeDeplacement(Plateau plateau,Case caseSelectionne);