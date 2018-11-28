
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

//empilage - dépilage
//Les piles et les files sont très utiles pour des programmes qui doivent traiter des données qui arrivent au fur et à mesure. 
//On dit que c'est un algorithme LIFO, ce qui signifie « Last In First Out ». 
//Traduction : « Le dernier élément qui a été ajouté est le premier à sortir »
//Les éléments de la pile sont reliés entre eux à la manière d'une liste chaînée

//on ne peut ajouter et retirer un élément qu'en haut de la pile.

typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};
typedef struct Pile Pile;
struct Pile{
    Element *premier;
};

Pile *initialiser(){
    Pile *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
    return pile;
}
void empiler(Pile *pile, int nvNombre){
    Element *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}
int depiler(Pile *pile){
    if (pile == NULL){
        exit(EXIT_FAILURE);
    }
    int nombreDepile = 0; //nombre dans la tête de la pile
    Element *elementDepile = pile->premier;

    if (pile != NULL && pile->premier != NULL){
        nombreDepile = elementDepile->nombre;
        pile->premier = elementDepile->suivant;
        free(elementDepile);
    }
    return nombreDepile;// Notre fonction depiler va donc retourner un int correspondant au nombre qui se trouvait en tête de pile
}
void afficherPile(Pile *pile){
    if (pile == NULL){
        exit(EXIT_FAILURE);
    }
    Element *actuel = pile->premier;

    while (actuel != NULL){
        printf("%d\n", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("\n");
}
int main(){
    Pile *maPile = initialiser();

    empiler(maPile, 4);
    empiler(maPile, 8);
    empiler(maPile, 15);
    empiler(maPile, 16);
    empiler(maPile, 23);
    empiler(maPile, 42);

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    printf("Je depile %d\n", depiler(maPile));
    printf("Je depile %d\n", depiler(maPile));

    printf("\nEtat de la pile :\n");
    afficherPile(maPile);

    return 0;
}