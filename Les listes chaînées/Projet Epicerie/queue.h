//********************************************************//
// Nom : queue.h                                          //
// Auteur : Marcel Andreazza                              //
// Date : Date : 18 novembre 2018					      //
// Le programme implemente une structure de données 	  //
// unidimensionnelle ainsi que tous les algorithmes       //
// rattachés et l’utilise dans une simulation discrète.   //
//********************************************************//

#pragma once
#define NB_DE_QUEUE 4
#define CYCLE_TEMPS 200
#define TAUX_ARRIVEE 2
#define MAX_CLIENT_QUEUE 10
#define VITESSE 100000 

//LIENS***************************************************//
#include "statistiques.h"

//STRUCTURES**********************************************//

//********************************************************//
//	Client                                                //
//********************************************************//
typedef struct Client Client;
struct Client{ 
	int tempsArrivee;
	int nbArticles;
	int temps; // nombre du cycle ou il est arrive
	Client* suivant;
};
//********************************************************//
//	Queue                                                 //
//********************************************************//
typedef struct Queue Queue;
struct Queue{
	Client* premier;
	Client* dernier;
};

//FONCTIONS QUEUE*****************************************//

//********************************************************//
// Initialiser à zero les queues.                         //
//********************************************************//
void InitialiserQueue(Queue* queue);

//********************************************************//
//  On peut savoir s'il y a quelqu'un dan la queue        //
//********************************************************//
int queueQuelqueUn(Queue* queue);

//********************************************************//
// Le nombre d’articles dans le panier d’un client suit   // 
// une distribution exponentielle.                        //
//********************************************************//
double randExpo(double lambda);

//********************************************************//
// Creer un client en donnant un instant d'arrive,        //
// un nombre d'arcticles.                       	      //
//********************************************************//
Client* creerClient(int temps, int nbOfItems);

//********************************************************//
// Cela va definir le Taux d'arrive de client             //
//********************************************************//
int randomizerClient(int hasardClient);

//********************************************************//
// Cela va definir la longuer de la queue                 //
//********************************************************//
//------------------------------------------------------------------------------------------------//
//	PSEUDO CODE:																				  //
//	Entrée : la queue (avec les informations du premier et du dernier client)					  //
// 		On va créer un client <quelqu’un> qui va être le premier dans la queue.				      //
//		Et aussi déclarer et initialiser une variable compteur appelée <longueur>, qu’on va       //
//		utiliser pour compter chaque cycle de la boucle suivant.								  //
//		Tant que "<quelqu’un> existe" soit vrai on exécute la boucle:							  //
//			MÉTODE : 																			  //
//			1. <quelqu’un> va être le suivant, alors de cette façon on va parcourir toute la      // 
//          queue en ajoutant 1 dans la longueur a chaque cycle.                                  //						                     	  */
//		Quand la condition n'est pas accomplie, on retourne la valeur de <longueur>.			  //
//------------------------------------------------------------------------------------------------//
int longueurQueue(Queue queue);

//********************************************************//
// Cela va definir quelle est la queue la plus courte     //
//********************************************************//
int queuePlusCourte(Queue* queue);

//********************************************************//
// Ajoute le client a la fin de la queue.                 //
//********************************************************//
//------------------------------------------------------------------------------------------------//
//	PSEUDO CODE:																				  //
//	Entrée : la queue (avec les informations du premier et dernier client) et le client           //
//	(avec l'instant qu'il est arrivé et le nombre d'articles dans le panier). 					  //
// 		Si le premier client dans la queue existe:												  //
//			On va creer un dernier client et en plus un client temporaire qui va devenir          //
//          le premier client.																      //
//			Tant que le client temporaire existe:												  //
// 				Le dernier va devenir le temporaire et le temporaire va devenir le suivant        //
//				du dernier (avec cela on arrive à la fin de la queue).							  //																		  */
//			Quand le client temporaire n'existe plus le suivant du dernier va devenir le client.  //
//      Sinon le premier de la queue va devenir un client.										  //
//------------------------------------------------------------------------------------------------//
void offrirClient(Queue* queue, Client* client);

//********************************************************//
//	S'il n'y a pas personne dans la queue (NULL) on       //
//  ajoute un client. Ensuite on l'enlève et on ajoute    // 
// 	le prochain client                                    //
//********************************************************//
void servirClient(Queue* queue, Statistiques* statistiques, int temps);

//********************************************************//
// Retourne le premier client dans la queue.		      //
// Si la queue est vide, NULL est retourne.               //
//********************************************************//
Client* coupDOeilTete(Queue queue);

//********************************************************//
// Retire et retourne le premier client dans la queue.	  //
// Si la queue est vide, NULL est retourne.               //
//********************************************************//
//------------------------------------------------------------------------------------------------//
//	PSEUDO CODE:																				  //
//	Entrée : la queue (avec les informations du premier et du dernier client).           		  //
//		Si le premier client dans la queue existe:											   	  //
//			On Retire et on retourne le premier client dans la queue.                 		      //
//			MÉTODE : 																			  //
//			[1]. On va créer un client auxiliaire qui garde les informations du premier.		  //
//			[2]. De cette façon on peut manipuler le premier comme on veut.              		  //
//			[3]. Et c’est cela qu’on fait : on dit que le premier va être le suivant.    		  //
//			[4]. Ensuite on retourne l'auxiliaire dans la queue (qui a assumée le premier).       //
//	Sinon on dirait qu’il n’y a pas personne dans la queue (vide) : NULL est retourne.   	      //
//------------------------------------------------------------------------------------------------//
Client* obtenirTete(Queue* queue);

//********************************************************//
//  1. Cette fonction enlève le nombre d'articles         //
//  2. Gere de données statistiques						  //
//  3. Execute la fonction <obtenir tête>				  //
//  4. Libère la mémoire utilisée à la fin du processus	  //
//********************************************************//
void misAjourQueue(Client* client, Queue* queue, Statistiques* statistiques, int temps);

//********************************************************//
// Cela imprime les 4 queue dans la console	              //
//********************************************************//
void imprimerQueue(Queue queue);