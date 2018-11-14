#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
EXERCICE
a) Observez "parenthesage Prefixe" Que fait-elle? (Indentifiez les 3 éléments)
b) Copiez "parenthesage Prefixe". Modifiez son code pour qu'il mette les parenthèses en postfixe "(a(b(c)))"
c) Programmez de manière recursive
		int palyndrome(char *mot, int longuer)
		qui détermine si les "longuers premièere lettre de mot formant un palyndrôme ("ABA",3) =1	
*/
void parenthesagePrefixe(char* c, int longueur)
{
	if (longueur == 0)
		return;

	printf("(");
	parenthesagePrefixe(c, longueur - 1);
	printf("%c)", c[longueur - 1]);
}
void parenthesageSuffixe(char* c, int longueur)
{
	if (longueur == 0)
		return;

	printf("(%c", c[0]);
	c++;
	parenthesageSuffixe(c, longueur - 1);
	printf(")");
}
int main()
{
	char mot[255]; 
	int longueur;
	printf("Entrez un mot\n");
	fgets(mot, 255, stdin);
	mot[strlen(mot) - 1] = '\0';
	longueur = strlen(mot);

	parenthesagePrefixe(mot, longueur);
	printf("\n");

	parenthesageSuffixe(mot, longueur);
	printf("\n");

//		printf("%s est un palyndrome.\n", mot);
//	else
//		printf("%s n'est pas un palyndrome.\n", mot);
}