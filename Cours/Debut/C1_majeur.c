// ****************************************************************************
// 
// Nom du fichier : grenouille.c
//
// Auteur : Marcel Andreazza
// 
// Date de création : 30 août 2018
//
// Decouvrir si l'utilisateur est majeur ou mineur
//
// ****************************************************************************

#include <stdio.h>
#include <stdlib.h>

int main()
{
	// ***************************************************************************
	// If, else, operateurs, scan, print
	// ***************************************************************************
	
	printf("Entrez votre date de naissance:\n");

	int anneeNaissance = 0;
	scanf("%d", &anneeNaissance);
	
	int age = (2018 - anneeNaissance);
	
	if (age < 18)
	{
		printf("Mineur\n");
	}
	else
	{
		printf("Majeur\n");
	}
}
