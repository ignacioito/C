//********************************************************//
// Nom : statistiques.h                                   //
// Auteur : Marcel Andreazza                              //
// Date : Date : 18 novembre 2018					      //
// Le programme implemente une structure de données 	  //
// unidimensionnelle ainsi que tous les algorithmes       //
// rattachés et l’utilise dans une simulation discrète.   //
//********************************************************//

#pragma once

//********************************************************//
//	Statistiques:                                         //
//********************************************************//
typedef struct Statistiques Statistiques;
struct Statistiques{
	int nombreClientsEntres;
	int nombreArticlesVendus;
	int tempsAttenteMoyen;
	int tempsAttenteMax;
	int nombreArticlesMax;
	int nombreArticlesMin;
};

//FONCTIONS STATISTIQUES**********************************//

//********************************************************//
// Cela va  mettre à zero tous les statistiques	proposés  //
//********************************************************//
Statistiques statistiquesInitialiser(Statistiques statistiques);

//********************************************************//
// Cela va imprimer les statistiques                	  //
//********************************************************//
void printStatistiques(Statistiques statistiques, int temps);