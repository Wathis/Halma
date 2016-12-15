#include "sauvegarde.h"



void sauvegarde(Plateau plateauDeJeu){

	extern int joueur;
	FILE* fichier = NULL;
	char tab[5] = {'h','a','l','m','a'};

	fichier = fopen(".sauvegarde.txt", "w");
	if(fichier != NULL)
	{


		fprintf(fichier, "%d\n\n", joueur);
		int i, j, k=0;
		for(i = 0; i < TAILLE; i++)
		{
			for(j = 0; j<TAILLE; j++)
			{
				fprintf(fichier,"%d",plateauDeJeu.tab[i][j]-48);
				k++;
				if(k == 5)
				{
					k = 0;
				}
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

	fichier = fopen(".sauvegarde.txt", "r");

	if(fichier != NULL)
	{
		joueur = fgetc(fichier)-48;
		retourALigne = fgetc(fichier);
		retourALigne = fgetc(fichier);
		int i,j;
		char tamp;
		for(i = 0; i < TAILLE; i++)
		{
			for(j = 0; j < TAILLE; j++)
			{
				plateauDeJeu->tab[i][j]=fgetc(fichier);
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




