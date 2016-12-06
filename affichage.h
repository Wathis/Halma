#include "structures.h"
//Les constantes de couleur
#define COLOR_NOIR  "\x1B[0m"
#define COLOR_ROUGE  "\x1B[31m"
#define COLOR_VERT  "\x1B[32m"
#define COLOR_JAUNE  "\x1B[33m"
#define COLOR_BLEU "\x1B[33m"
#define COLOR_MAGENTA  "\x1B[35m"
#define COLOR_CYAN "\x1B[36m"
#define COLOR_BLANC  "\x1B[37m"
#define COLOR_RESET   "\x1b[0m"
#define FAIRE_CLIGNOTER "\x1b[5m"
#define STOP_CLIGNOTER "\x1b[25m"

void afficherLePlateau(Plateau *plateau);
void afficherLeMessageDuMenu();
void erreur(char Message[]);