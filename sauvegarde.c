#include "sauvegarde.h"



void sauvegarde(Plateau plateauDeJeu){

extern int joueur;
FILE* fichier = NULL;

fichier = fopen("sauvegarde.txt", "w");
if(fichier != NULL)
{


	fprintf(fichier, "%d\n\n", joueur);
	int i, j;
	for(i = 0; i < TAILLE; i++)
	{
		for(j = 0; j<TAILLE; j++)
		{
			fprintf(fichier,"%d",plateauDeJeu.tab[i][j]);
		}
		fprintf(fichier, "\n");
	
	}
	fclose(fichier);
}
else{
	printf("Impossible d'ouvrir le fichier");
}

}

void chargerSauvegarde(Plateau *plateauDeJeu)
{

extern int joueur;
FILE* fichier = NULL;
int retourALigne;

fichier = fopen("sauvegarde.txt", "r");

if(fichier != NULL)
{
	int i,j;
	char tamp;
	for(i = 0; i < TAILLE; i++)
	{
		for(j = 0; j < TAILLE; j++)
		{
			plateauDeJeu->tab[i][j]=fgetc(fichier)-'0';
		//	printf("%d", fgetc(fichier)-'0' );		
		}
 	retourALigne=fgetc(fichier);
	
	}
	fclose(fichier);
}
else
{
	printf("Impossible d'ouvrir le fichier");
}
}




