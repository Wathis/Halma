#include "sauvegarde.h"



void sauvegarde(Plateau plateauDeJeu){

extern int joueur;
FILE* fichier = NULL;

fichier = fopen(".sauvegarde.txt", "w");
if(fichier != NULL)
{


	fprintf(fichier, "%d\n\n", joueur);
	int i, j, k=0;
	char tab[8] = {'h','a','l','m','a','i','f','s'};
	
	for(i = 0; i < TAILLE; i++)
	{
		for(j = 0; j<TAILLE; j++)
		{
			fprintf(fichier,"%d",plateauDeJeu.tab[i][j]-48+tab[k]-60);
			k++;
			if(k == 8)
			{
				k = 0;
			}
		}
	
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
	int i,j,k;
	char tamp, var1, var2;
	char tab[8] = {'h','a','l','m','a','i','f','s'};
	for(i = 0; i < TAILLE; i++)
	{
		for(j = 0; j < TAILLE; j++)
		{
		       	k++;
			if(k == 8){k=0;}	
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




