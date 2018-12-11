#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimerTableau(int tab[], int n)
{
  for (int i = 0; i < n; i ++)
    printf("%d%s", tab[i], ((i < n - 1) ? ", " : "\n"));
}

void echanger(int* a, int* b)
{
  int t = *b;
  *b = *a;
  *a = t;
}

// début inclusif
// milieu à droite
// fin exclufif
void fusionner(int in[], int out[], int debut, int milieu, int fin)
{
  int a = debut;
  int b = milieu;
  for (int i = debut; i < fin; i++)
    if ((a < milieu) && ((in[a] < in[b]) || (b >= fin)))
      out[i] = in[a++];
    else
      out[i] = in[b++];
}

// debut inclusif, fin exclusif
void triFusion(int in[], int out[], int debut, int fin)
{
  if (fin - debut < 2)
    return;
  int milieu = (debut + fin) / 2;

  triFusion(out, in, debut, milieu);
  triFusion(out, in, milieu, fin);
  fusionner(in, out, debut, milieu, fin);
}
void triSelection(int* tab, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i + 1; j < n; j++)
      if (tab[min] > tab[j])
        min = j;
    echanger(tab + i, tab + min);
  }
}
void triInsertion(int* tab, int n)
{
  for (int i = 1; i < n; i++)
    for (int j = i; (j > 0) && (tab[j - 1] > tab[j]); j--)
      echanger(tab + j, tab + j - 1);
}
void triABulle(int* tab, int n)
{
  int temoin = 1;
  while (temoin)
  {
    temoin = 0;
    for (int i = 1; i < n; i++)
      if (tab[i - 1] > tab[i])
      {
        echanger(tab + i - 1, tab + i);
        temoin = 1;
      }
    n--;
  }
}
int main()
{
  srand(time(NULL));
  const int TAILLE = 100000;
  int tab[TAILLE];
  int copie[TAILLE];
  int bulle[TAILLE];
  int insertion[TAILLE];
  int selection[TAILLE];


  for (int i = 0; i < TAILLE; i++)
  {
    tab[i] = rand() % TAILLE;
    copie[i] = tab[i];
    insertion[i] = tab[i];
    bulle[i] = tab[i];
    selection[i] = tab[i];
    insertion[i] = tab[i];
  }
  //printf("DÉBUT TRI FUSION\n");
  //imprimerTableau(tab, TAILLE); 

  clock_t debut = clock();
  triFusion(copie, tab, 0, TAILLE);

  clock_t fin = clock();
  printf("\nFIN TRI FUSION (%lf secondes)\n", (double)(fin-debut)/CLOCKS_PER_SEC);
  //imprimerTableau(tab, TAILLE);
  printf("\n");
//----------------------------------------------------------------------------------------
  //printf("DÉBUT TRI BULLE\n");
  //imprimerTableau(tab, TAILLE); 

  debut = clock();
  triABulle(bulle, TAILLE);

  fin = clock();
  printf("\nFIN TRI BULLE (%lf secondes)\n", (double)(fin-debut)/CLOCKS_PER_SEC);
  //imprimerTableau(tab, TAILLE);
  printf("\n");
  //----------------------------------------------------------------------------------------
  //printf("DÉBUT TRI INSERTION\n");
  //imprimerTableau(tab, TAILLE); 

  debut = clock();
  triInsertion(insertion, TAILLE);

  fin = clock();
  printf("\nFIN TRI INSERTION (%lf secondes)\n", (double)(fin-debut)/CLOCKS_PER_SEC);
  //imprimerTableau(tab, TAILLE);
   printf("\n");
  //----------------------------------------------------------------------------------------
  //printf("DÉBUT TRI SELECTION\n");
  //imprimerTableau(tab, TAILLE); 

  debut = clock();
  triSelection(selection, TAILLE);

  fin = clock();
  printf("\nFIN TRI SELECTION (%lf secondes)\n", (double)(fin-debut)/CLOCKS_PER_SEC);
  //imprimerTableau(tab, TAILLE);
   printf("\n");
}
