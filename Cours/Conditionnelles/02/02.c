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
/* année est bisextile si elle se divise par 4 mais
non par 100, ou si elle se divise par 400.
Ex : 1600, 2000, 1996 et 2004 sont bisextiles.
1900, 1999, 2001 et 2002 ne le sont pas.
Déterminez si une année entrée par l’usager est bisextile.*/


	printf("Entrez une année pour decouvrir s'il est bisextile\n");
	
	int nb;
	scanf("%d", &nb);

	if (nb % 4 == 0 && nb % 100 != 0 && nb % 400 != 0)
	{ 
		printf("Le nombre %d est bisextile\n", nb);
	}
	else
	{
		printf("Le nombre %d n'pasest bisextile\n", nb);
	}
}
