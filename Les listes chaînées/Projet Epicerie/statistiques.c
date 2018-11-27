//********************************************************//
// Nom : statistiques.c                                   //
// Auteur : Marcel Andreazza                              //
// Date : Date : 18 novembre 2018					      //
// Le programme implemente une structure de données 	  //
// unidimensionnelle ainsi que tous les algorithmes       //
// rattachés et l’utilise dans une simulation discrète.   //
//********************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

//LIENS***************************************************//
#include "queue.h"
#include "statistiques.h"

//FONCTIONS:STATISTIQUES**********************************//

//********************************************************//
Statistiques statistiquesInitialiser(Statistiques statistiques){
	statistiques.nombreClientsEntres = 0;
	statistiques.nombreArticlesVendus = 0;
	statistiques.tempsAttenteMoyen = 0;
	statistiques.tempsAttenteMax = 0;
	statistiques.nombreArticlesMax = 0;
	statistiques.nombreArticlesMin = 0;
	return statistiques;
}
//********************************************************//
void printStatistiques(Statistiques statistiques, int temps){
		printf("\n");
	printf("****************** Statistiques ******************\n\n");
	printf("* Nombre de clients entrés  : %.5d clients      *\n", statistiques.nombreClientsEntres);
	printf("* Nombre d’articles vendus  : %.5d articles     *\n", statistiques.nombreArticlesVendus);
	if(statistiques.nombreClientsEntres!=0)
	printf("* Temps d’attente moyen     : %.5d cycles       *\n", statistiques.tempsAttenteMoyen / statistiques.nombreClientsEntres);
	printf("* Temps d’attente maximum   : %.5d cycles       *\n", statistiques.tempsAttenteMax);
	printf("* Nombre d’articles maximum : %.5d articles     *\n", statistiques.nombreArticlesMax);
	printf("* Nombre d’articles minimum : %.5d articles     *\n", statistiques.nombreArticlesMin);
	int nombreArticlesVendus;
	printf("* Nombre d’articles moyen   : %.5d articles     *\n", (statistiques.nombreClientsEntres > 0)? statistiques.nombreArticlesVendus / statistiques.nombreClientsEntres : 0);
	printf("* Nombre de cycles          : %.5d cycles       *\n\n", temps);
	printf("**************************************************\n");
}
//********************************************************//