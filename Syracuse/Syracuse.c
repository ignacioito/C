#include <stdio.h>
#include <stdlib.h>

//LES ETAPES POUR LE FONCTIONS RECURSIVE
// 1. Une condition de sortie: quand n veut 1
// 2. Un appel recursif : syracuse (n/2) ou syracuse (3n+1)
// 3. Un calcul de plus imprimer l'element de la suite
/*-----------------------------------------------*/
// 1.La suite de Syracuse
// 2.On part d'un nombre naturel ex: 14
//		3.Chaque etape, si n est pair,
//		4.On divise par 2
// 5.Si est impar, on le multiplie par trois
// 6.Et on ajoute 1
// 7.On arrête à 1

void syracuse(int n){
	printf("%d\n", n);
	if(n == 1)
		return;
	if(n % 2 == 0)
		syracuse (n/2);
	else
		syracuse ((n*3) + 1);
//printf("%d\n", n); Se eu coloco o print aqui ele imprime a pilha inversamente
/*-----------------------------------------------*/
int main(){
	syracuse(10);
}
