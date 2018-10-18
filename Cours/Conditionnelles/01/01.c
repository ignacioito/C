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
	printf("Entrez un nombre pour decouvrir sa nature:\n");

	int nombre;
	scanf("%d", &nombre);
	if (nombre > 0)
	{
		printf("Positive (+) %d\n", nombre);
	}
	if (nombre < 0)
	{
		printf("Negatif (-) %d\n", nombre);
	}
	if (nombre == 0)
	{
		printf("Nul (0) %d\n", nombre);
	}	
	
}
