#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

/*

[Déclaration tableau]
    <type> <nom_tableau>[X]; X c'est l'indice

[Initialisation]
    int tableauX [5] = {valeur1, valeur2. valeur3, valeur4, valeur5}
    int tableauX [5] = {0} Tous le cases sont zero.
    int tableauX [5] = {4} Première case à 4, le reste à zero.

[Accés au tableau]
    tableau[X] : élément d'indice ( X+1éme du tableau)
    
    tableau : l'adresse du tableau
    *tableau : le premier element du tableau
    *(tableau + X): élément d"indice X  

[NOTE]
    tableau[5] même chose que : *(tableau + 5)
    Tableau c'est un pointeur vers le premier élément
*/

/*----------------------------------------------------------------*/

#define TailleTableau 5
#define NOMBRE_LIGNE 3
#define NOMBRE_COLONE 2

/*----------------------------------------------------------------*/
void afficher_tableau1(int* tableauY, int taille){ 
//(int tableauY[], int taille) je peux faire de cette façon aussi
    for(int i = 0; i < taille; i++)
        printf("[%d] ", tableauY[i]); // La façon plus utilisée
    printf("\n");
}
/*----------------------------------------------------------------*/
void afficher_tableau2(int* tableauZ, int taille){
//(int tableauY[], int taille) Une autre syntaxe
    for(int i = 0; i < taille; i++)
        printf("[%d] ", *(tableauZ + i)); // La façon moins utilisée (est venu avant)
    printf("\n");
}
/*----------------------------------------------------------------*/
int* creerTableau(void){
    static int tableauEntiers[TailleTableau];   
    for(int i = 0; i < 5; i++) 
        tableauEntiers[i] = (i * 3);
    return tableauEntiers; 
}
/*----------------------------------------------------------------*/
void afficher_tableauF(int* tab, int taille){
    for( int i = 0; i < taille; i++)
        printf("[%d] ",tab[i]);
} 
/*----------------------------------------------------------------*/
void imprimerMatrice(const int nbRangees, const int nbColonnes, int matrice[nbRangees][nbColonnes]){
	for (int i = 0; i < nbRangees; i++){
		for (int j = 0; j < nbColonnes; j++)
			printf("[%d] ", matrice[i][j]);
		printf("\n");
    }
}
/*----------------------------------------------------------------*/
int main(void){
    int tableauX [5];
    tableauX [0] = 14;
    tableauX [1] = 5;
    tableauX [2] = -15;
    tableauX [3] = 10;
    tableauX [4] = 18;
    //int tableauX[5] = {14, 5, -15, 10, 18}

    afficher_tableau1(tableauX, TailleTableau);
    afficher_tableau2(tableauX, TailleTableau);

    int* TableauF = creerTableau();
    afficher_tableauF(TableauF,TailleTableau);
    
    //tableau avec deux dimension(matrice)
 	int matrice[4][3] = {{-10, 5, 4}, {5, 6, 9}, {44, 0, 4}, {1, 9, 9}};
	imprimerMatrice(4,3,matrice); // On doit envoyer à fonction premièrement la taille de la matrice.
}
