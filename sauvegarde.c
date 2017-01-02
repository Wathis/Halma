#include "sauvegarde.h"



void sauvegarde(Plateau plateauDeJeu){
	
	// récupération de la variable joueur
	extern int joueur;

	// création d'un pointeur
	FILE* fichier = NULL;
	
	// le pointeur fichier est pointé sur le fichier ".sauvegarde.txt"
	fichier = fopen(".sauvegarde.txt", "w");

	// on test si le fichier est bien ouvert
	if(fichier != NULL)
	{

		// on écrit dans le fichier le numéro du joueur qui est en train de jouer
		fprintf(fichier, "%d\n\n", joueur);

		// initialisation des variables i,j,k
		int i, j, k=0;

		// initialisation de la clé de codagee
		char tab[8] = {'h','a','l','m','a','i','f','s'};
	
		// on écrit dans le fichier le plateau de jeu 
		for(i = 0; i < TAILLE; i++)
		{
			for(j = 0; j<TAILLE; j++)
			{
				//chaque case du  plateau de jeu est crypté puis écrit dans le fichier ".sauvegarde.txt"
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
		// message dans le cas où le fichier ne s'ouvre pas
		printf("Impossible d'ouvrir le fichier");
	}

}

// fonction qui permet de charger une sauvbegarde
void chargerSauvegarde(Plateau *plateauDeJeu)
{

	extern int joueur;
	FILE* fichier = NULL;
	int retourALigne;

	fichier = fopen(".sauvegarde.txt", "r");

if(fichier != NULL)
{
	// récupération du numéro du joueur qui doit jouer
	joueur = fgetc(fichier)-48;
	
	//déplacement au sein du fichier
	retourALigne = fgetc(fichier);
	retourALigne = fgetc(fichier);

	// initialisation des variables internes à la fonction
	int i,j,k=0, tamp1, tamp2;
	char tab[8] = {'h','a','l','m','a','i','f','s'};

	for(i = 0; i < TAILLE; i++)
	{
		for(j = 0; j < TAILLE; j++)
		{	
			//récupération de 2 numéros à la suite
			tamp1 = fgetc(fichier)-48;
			tamp2 = fgetc(fichier)-48;

			// concaténation des variables tamp1 et tamp2 pour récupérer le code acsii
			tamp1 = tamp1*10 + tamp2;

			// on décrypte et on place la sauvegarde dans la structure  plateau de jeu 
			plateauDeJeu->tab[i][j] = tamp1+108-tab[k];

			k++;
			if(k == 8){k=0;}	
		}
		
		
	}
		fclose(fichier);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier");
	}
}




