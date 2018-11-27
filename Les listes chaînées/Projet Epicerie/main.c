//********************************************************//
// Nom : main.c                                           //
// Auteur : Marcel Andreazza                              //
// Date : Date : 19 novembre 2018					      //
// Le programme implemente une structure de données 	  //
// unidimensionnelle ainsi que tous les algorithmes       //
// rattachés et l’utilise dans une simulation discrète.   //
//********************************************************//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

//LIENS**************************************************//
#include "queue.h"
#include "statistiques.h"

//MAIN***************************************************//
int main (){
	srand(time(NULL));
	Queue queue [NB_DE_QUEUE];
	int temps;
	Statistiques statistiques;
	statistiques = statistiquesInitialiser(statistiques);
	InitialiserQueue(queue);
	int hasard = 0;
	for (temps = 1; (temps <= CYCLE_TEMPS) || queueQuelqueUn(queue); temps++){
			if ((randomizerClient(hasard)) && (temps <= CYCLE_TEMPS)){
			servirClient(queue, &statistiques, temps);
			}
			for (int i = 0; i < NB_DE_QUEUE; i++){
				Client* client = coupDOeilTete(queue[i]);
				if (client != NULL)
				misAjourQueue(client, &queue[i], &statistiques, temps);
				printf("queue(%d): ", i + 1);
				imprimerQueue(queue[i]);
				printf("\n");
			}
			printStatistiques(statistiques, temps);
			usleep(VITESSE);
			system("clear");
	}
	printStatistiques(statistiques, temps);
}
