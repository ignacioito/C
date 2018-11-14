// ***************************************************************************************************
// Nom : types.c
// Auteur : Marcel Andreazza
// Date : 4 septembre 2018
// Réponse aux exercices de VariablesTypesOperateurs.pdf, page 19
// ***************************************************************************************************

#include <stdio.h>
#include <stdlib.h>


int factorielle(int n){
	if(n == 1){
		return printf("%d\n", n);
		;
	}
	printf("%d\n", n );
	return (n * factorielle(n-1));


}
int main(){
	factorielle(10);
}