// ***************************************************************************************************
// Nom : types.c
// Auteur : Marcel Andreazza
// Date : 4 septembre 2018
// Réponse aux exercices de VariablesTypesOperateurs.pdf, page 19
// ***************************************************************************************************

#include <stdio.h>
#include <stdlib.h>


void methodeMystere(long n){
	if(n == 0){
		return;
	}
	methodeMystere(n/2);
	printf("%ld\n", (n%2));
}
int main(){
	methodeMystere(9);
}