// *******************************************************************************
//
// Nom de fichier: majeur.c
// Date de création : 30 aoüt
// Auteur : Marcel Andreazza
// Description : valide si les personne nees a l'annee de naissance 
// fournie sont majeur au Canada
//
// *******************************************************************************

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int compteur = 0;
	int compteur2 = 0;

	while (compteur < 10)
	{
		compteur2 = compteur;
		while(compteur2 >= 0)
		{
			printf("%d ", compteur2);
			compteur2--;
		}
		compteur++;
		printf("\n");
	}
}