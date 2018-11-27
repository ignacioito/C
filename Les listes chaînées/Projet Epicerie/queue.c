//********************************************************//
// Nom : queue.c                                          //
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

//FONCTIONS QUEUE*****************************************//

//********************************************************//
void InitialiserQueue(Queue* queue){
	for (int i = 0; i < NB_DE_QUEUE; i++){
		queue[i].premier = NULL;
		queue[i].dernier = NULL;
	}
}
//********************************************************//
int queueQuelqueUn(Queue* queue){
	for (int i = 0; i < NB_DE_QUEUE; i++){
		if(queue[i].premier != NULL){
			return 1;
		}
	}
	return 0;
}
//********************************************************//
double randExpo(double lambda)
{
    double u = rand() / (RAND_MAX + 1.0);
    return (-log(1 - u) / lambda) + 1;
}
//********************************************************//
Client* creerClient(int temps, int nbOfItems)
{
	Client* nouveau = (Client*)malloc(sizeof(Client));
	nouveau->tempsArrivee = temps;
	nouveau->nbArticles = nbOfItems;
	nouveau->suivant = NULL;
	return nouveau;
}
//********************************************************//
int randomizerClient(int hasardClient){
 	int noveauClientArrive = rand () % TAUX_ARRIVEE;
	return noveauClientArrive;
}
//********************************************************//
int longueurQueue(Queue queue)
{
	Client* quelqun = queue.premier;
	int longueur = 0;
	while (quelqun != NULL)
	{
		quelqun = quelqun->suivant;
		longueur++;
	}
	return longueur;
}
//********************************************************//
int queuePlusCourte(Queue* queue)
{
	int queuePlusPetit = MAX_CLIENT_QUEUE;
	int comptQueueCaisse = 0;
	int nombreDeCaisse = 0;
	for (int i = 0; i < NB_DE_QUEUE; i++)
	{
		comptQueueCaisse = longueurQueue(queue[i]);
		if (comptQueueCaisse < queuePlusPetit)
		{
			queuePlusPetit = comptQueueCaisse;
			nombreDeCaisse = i;
		}
	}
	return nombreDeCaisse;
}
//********************************************************//
void offrirClient(Queue* queue, Client* client){
	if (queue->premier != NULL){
		Client* dernier;
		Client* temporaire = queue->premier;
		while (temporaire != NULL){
			dernier = temporaire;
			temporaire = dernier->suivant;}
		dernier->suivant = client;
	}
	else
		queue->premier = client;
}
//********************************************************//
void servirClient(Queue* queue, Statistiques* statistiques, int temps){
	Client* nouveau = creerClient(temps, randExpo(1.0/9)); // on va envoi 
	offrirClient(&queue[queuePlusCourte(queue)], nouveau);

	statistiques->nombreArticlesVendus += nouveau->nbArticles;
	if (statistiques->nombreArticlesMax < nouveau->nbArticles)
		statistiques->nombreArticlesMax = nouveau->nbArticles;
	if (statistiques->nombreArticlesMin == 0 || statistiques->nombreArticlesMin > nouveau->nbArticles)
		statistiques->nombreArticlesMin = nouveau->nbArticles;
	statistiques->nombreClientsEntres++;
}
//********************************************************//
Client* coupDOeilTete(Queue queue){
	if (queue.premier != NULL)
		return queue.premier;
	else
		return NULL;
}
//********************************************************//
Client* obtenirTete(Queue* queue)
{
	if (queue->premier != NULL)
	{
		Client* aux = queue->premier;
		queue->premier = queue->premier->suivant;
		return aux;
	}
	else
		return NULL;
}
//********************************************************//
void misAjourQueue(Client* client, Queue* queue, Statistiques* statistiques, int temps){
	client->nbArticles--;
	if (client->nbArticles == 0){
	    if ((temps - client->tempsArrivee) > statistiques->tempsAttenteMax)
	        statistiques->tempsAttenteMax = temps - client->tempsArrivee;
	    statistiques->tempsAttenteMoyen += temps - client->tempsArrivee;
		obtenirTete(queue);
		free(client);
	}
}
//********************************************************//
void imprimerQueue(Queue queue){
	Client* aux = queue.premier;
	while (aux != NULL){
		printf("(T: %d A: %d)", aux->tempsArrivee, aux->nbArticles);
		aux = aux->suivant;
	}
}
//********************************************************//