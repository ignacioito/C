// *****************************************************************************
// Nom : boucles.c
//
// Auteur : Rébecca
//
// Date : 7 septembre 2018
//
// Réponse aux exercices de boucles ConditionnellesEtBoucles.pdf
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // *************************************************************************
    // Cinq étoiles
    // *************************************************************************
    const int COTE = 5;
    
    int rangee = 0;
    int colonne = 0;
    
    while (rangee < COTE)
    {
		colonne = 0;
		while (colonne < COTE)
		{
		    printf("* ");
		    colonne++;
		}
		printf("\n");
		rangee++;
    }

    // *************************************************************************
    // 1 à 10 étoiles
    // *************************************************************************
    const int MIN = 1;
    const int MAX = 10;
    int largeur = MAX;

    printf("\n\nEntrez un nombre entre %d et %d (inclusivement)\n", MIN, MAX);
    scanf("%d", &largeur);
    
    if ((largeur < MIN) || (largeur > MAX))
        largeur = MAX;

    rangee = 0;
    
    while (rangee < largeur)
    {
		colonne = 0;
		while (colonne < largeur)
		{
		    printf("* ");
		    colonne++;
		}
		printf("\n");
		rangee++;
    }

    // *************************************************************************
    // 1 à 10 étoiles, redemander à l'utilisateur en cas d'entrée invalide.
    // *************************************************************************
    largeur = 0;

    while ((largeur < MIN) || (largeur > MAX))
    {
        printf("\n\nEntrez un nombre entre %d et %d (inclusivement)\n", MIN, MAX);
        scanf("%d", &largeur);
    }

    rangee = 0;
    
    while (rangee < largeur)
    {
		colonne = 0;
		while (colonne < largeur)
		{
		    printf("* ");
		    colonne++;
		}
		printf("\n");
		rangee++;
    }
}