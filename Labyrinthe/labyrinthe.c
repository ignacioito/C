//*********************************************************
// retourSurTrace.c
// Rébecca
// 30 novembre 2018
//
// Exemple de retour sur trace : les dames
//*********************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curses.h>
#include <unistd.h>
#define TAILLE 4
int compteur = 0;
#define LABYRINTHE 8
#define DESSIN_MUR "▇▇"// unicode
#define DESSIN_SOURIS " *"
#define DESSIN_VIDE "  "
#define DESSIN_FROMAGE "🧀" // unicode

//*********************************************************
// int libre(int echiquier[TAILLE][TAILLE], int x, int y)
// Détermine si la case (x,y) est libre dans l'échiquier
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//    x, y : les coordonnées de la case dans l'échiquier
//
// OUTPUT : 
//    1 si la case x,y est libre, 0 sinon.
//*********************************************************
int libre(int echiquier[TAILLE][TAILLE], int x, int y)
{
  for (int i = 0; i < TAILLE; i++)
  {
    if (echiquier[x][i] || echiquier[i][y])
      return 0;
    for (int j = 0; j < TAILLE; j++)
      if (echiquier[i][j] && ((i + j == x + y) || (i - j == x - y))) //diagonal
	     return 0;
  }
  return 1;
}

//*********************************************************
// void printEchiquier(int echiquier[TAILLE][TAILLE])
// Imprime l'échiquier à la console.
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//*********************************************************
void printEchiquier(int echiquier[TAILLE][TAILLE])
{
  for (int i = 0; i < TAILLE; i++)
  {
      for (int j = 0; j < TAILLE; j++)
        printf("%d ", echiquier[i][j]);
    printf("\n");
  }
  printf("\n");
}

void printLabyrinthe(int labyrinthe[LABYRINTHE][LABYRINTHE])
{
  printf("%s%s%s%s%s%s%s%s", DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR);
  printf("\n");
  for (int i = 0; i < LABYRINTHE; i++)
  {
      for (int j = 0; j < LABYRINTHE; j++)
      {
      	if(i == LABYRINTHE-1 && j == LABYRINTHE-1)
      		printf("%s", DESSIN_FROMAGE);
      	else switch(labyrinthe[i][j])
      	{
      		case 0:
      		printf("%s", DESSIN_VIDE);
      		break;
      		case 1:
      		printf("%s", DESSIN_MUR);
      		break;
      		case 2:
      		printf("%s", DESSIN_SOURIS);
      		break;
      	}
      }

    //printf("%d ", labyrinthe[i][j]);
    printf("\n");
  }
  
  printf("%s%s%s%s%s%s%s%s", DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR,DESSIN_MUR);
  printf("\n");
}
  

//*********************************************************
// int dames(int echiquier[TAILLE][TAILLE], int nbDames)
// Détermine si nbDames dames peuvent être placées dans 
// l'échiquier sans qu'une puisse en manger une autre.
//
// INPUT :
//    echiquier : Une matrice dont la case i,j est 1
//      Si une dame s'y trouve et 0 sinon.
//    nbDames : le nombre de dames à placer
//
// OUTPUT : 
//    1 si nbDames peuvent être placées dans l'échiquier
//    0 sinon.
//*********************************************************
int dames(int echiquier[TAILLE][TAILLE], int nbDames)
{
  if(nbDames == 0)
  {	
  	compteur++; //para imprimir somente o numero de formatos possiveis
  	//printEchiquier(echiquier); //para imprimir cada uma das soluçoes
  	//printf ("NB formats: %d\n", ++compteur);
  }
  //for(int i = 0; i < TAILLE; i++)
  int i = TAILLE - nbDames; //força o primeiro elemento a ser colocado no primeiro local da matriz 0,0
  for (int j = 0; j < TAILLE; j++)
  {
  	if(libre(echiquier, i,j))
	{
		echiquier[i][j] = 1;
		if(dames(echiquier, nbDames - 1))
			return 1;
		echiquier[i][j] = 0;
	}
  }return 0;
}

//*********************************************************
int chemin (int labyrinthe[LABYRINTHE][LABYRINTHE], int x, int y) //x = position souris dans le labyrinthe; y = position colonne
{
	labyrinthe[x][y] = 2;
	
	if (y == (LABYRINTHE-1) && x == (LABYRINTHE-1)) //condition de sortie
		printLabyrinthe(labyrinthe);
		
	if (y+1 < LABYRINTHE)
		if (labyrinthe[x][y+1] == 0)
			if (chemin(labyrinthe, x, y+1) == 1)
				return 1;
	if (x+1 < LABYRINTHE)
		if (labyrinthe[x+1][y] == 0)
			if (chemin(labyrinthe, x+1, y) == 1)
				return 1;
  	if (y-1 >= 0)
		if (labyrinthe[x][y-1] == 0)
			if (chemin(labyrinthe, x, y-1) == 1)
				return 1;
	if (x-1 >= 0)
		if (labyrinthe[x-1][y] == 0)
			if (chemin(labyrinthe, x-1, y) == 1)
				return 1;
	
  	labyrinthe[x][y] = 0;	
  	return 0;
}
  
//*********************************************************
// Pilote pour le problème des dames.
//*********************************************************
int main()
{
  int echiquier[TAILLE][TAILLE];
  for (int i = 0; i < TAILLE; i++)
    for (int j = 0; j < TAILLE; j++)
      echiquier[i][j] = 0;
  dames(echiquier, TAILLE);  
  //printEchiquier(echiquier); 
  printf("NB formats: %d\n", compteur); 

  //int labyrinthe[LABYRINTHE][LABYRINTHE] = {{0,0,1,0,0},{0,0,0,1,0},{0,1,0,1,0},{0,1,0,0,0},{0,0,0,1,0}};
  //chemin(labyrinthe,0,0);

  int labyrinthe[LABYRINTHE][LABYRINTHE] = {{0,0,1,0,0,0,0,0},{0,1,1,0,1,1,1,0},{0,0,0,0,1,0,0,0},{0,1,1,0,1,0,1,0},{1,1,1,0,1,0,1,1},{0,0,0,0,1,0,1,0},{1,1,1,0,1,0,1,0},{1,0,0,0,1,0,0,0}};
  chemin(labyrinthe,0,0);
}
