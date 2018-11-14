// ***************************************************************************************************
// Nom : types.c
// Auteur : Marcel Andreazza
// Date : 4 septembre 2018
// Réponse aux exercices de VariablesTypesOperateurs.pdf, page 19
// ***************************************************************************************************

#include <stdio.h>
#include <stdlib.h>

//LES ETAPES POUR LE FONCTIONS RECURSIVE
// 1. Une condition de sortie: quand n veut 1
// 2. Un appel recursif : syracuse (n/2) ou syracuse (3n+1)
// 3. Un calcul de plus imprimer l'element de la suite
//______________________________________________

// La suite de Syracuse
// On part d'un nombre naturel ex: 14
//		chaque etape, si n est pair,
//		on divise par 2
// Si est impar, on le multiplie par trois
// Et on ajoute 1
// On arrête à 1

void syracuse(int n){
	printf("%d\n", n);
	if(n == 1)
		return;
	if(n % 2 == 0)
		syracuse (n/2);
	else
		syracuse ((n*3) + 1);
//	printf("%d\n", n); Se eu coloco o print aqui ele imprime a pilha inversamente
}
int main(){
	syracuse(10);
}