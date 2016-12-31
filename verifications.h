#include "saisie.h"

int verificationDeSelection(Plateau *plateau,Case *caseATester,int joueur);
int verificationDeDeplacement(Plateau *plateau,Case caseSelectionne,Case caseDeplacement,int typeVerification);
int testDeCase(Plateau *plateau,Case *caseATester);
int nbrSautPossible(Plateau *plateau,Case caseSelectionne);
int verificationDeWin(Plateau *plateau,int joueur);
int indicationDeDeplacement(Plateau plateau,Case caseSelectionne,int typeIndication);