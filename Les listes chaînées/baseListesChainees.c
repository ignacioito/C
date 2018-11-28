#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/*
initialiser la liste ;
ajouter un élément ;
supprimer un élément ;
afficher le contenu de la liste ;
supprimer la liste entière.
*/

typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste{
    Element *premier;
};

Liste *initialisation(){
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL){
        exit(EXIT_FAILURE);
    }

    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element; //Nous avons donc maintenant réussi à créer en mémoire une liste composée d'un seul élément

    return liste;
}
void insertion(Liste *liste, int nvNombre){
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));

    if (liste == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }
    nouveau->nombre = nvNombre;/* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier; /* si vous faites d'abord pointerpremiervers notre nouvel élément,vous perdez l'adresse du premier élément de la liste !  */
    liste->premier = nouveau;   
}
void suppression(Liste *liste){
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }
    if (liste->premier != NULL){ //On vérifie ensuite qu'il y a au moins un élément dans la liste, sinon il n'y a rien à faire.
        Element *aSupprimer = liste->premier; // sauvegarder l'adresse de l'élément à supprimer dans un pointeur aSupprimer
        liste->premier = liste->premier->suivant; // On adapte ensuite le pointeurpremier vers le nouveau premier élément, qui est actuellement en seconde position de la liste chaînée.
        free(aSupprimer);
    }
}
void afficherListe(Liste *liste){
    if (liste == NULL){
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL){
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}
int main(void){
    Liste *maListe = initialisation();

    insertion(maListe, 4);
    insertion(maListe, 8);
    insertion(maListe, 15);
    suppression(maListe);
    
    afficherListe(maListe);

    return 0;
}
