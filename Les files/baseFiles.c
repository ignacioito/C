
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

//Le premier qu'on fait sortir de la file est le premier à être arrivé. 
//On parle ici d'algorithme FIFO (First In First Out), c'est-à-dire « Le premier qui arrive est le premier à sortir ».

typedef struct Element Element;
struct Element{
    int nombre;
    Element *suivant;
};
typedef struct File File;
struct File{
    Element *premier;
};

File *initialiser(){
    File *file = malloc(sizeof(*file));
    file->premier = NULL;
    return file;
}
void enfiler(File *file, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (file == NULL || nouveau == NULL){
        exit(EXIT_FAILURE);
    }

    nouveau->nombre = nvNombre;
    nouveau->suivant = NULL;

    if (file->premier != NULL) /* La file n'est pas vide */{
        /* On se positionne à la fin de la file */
        Element *elementActuel = file->premier;
        while (elementActuel->suivant != NULL){ //il faut se placer à la fin de la file pour ajouter le nouvel élément.
            elementActuel = elementActuel->suivant;
        }
        elementActuel->suivant = nouveau;}
    else /* La file est vide, notre élément est le premier */{
        file->premier = nouveau;
    }
}
int defiler(File *file){ 
// Le défilage ressemble étrangement au dépilage. Étant donné qu'on possède un pointeur vers le premier élément de la file, il nous suffit de l'enlever et de renvoyer sa valeur.
    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    int nombreDefile = 0;

    /* On vérifie s'il y a quelque chose à défiler */
    if (file->premier != NULL){
        Element *elementDefile = file->premier;

        nombreDefile = elementDefile->nombre;
        file->premier = elementDefile->suivant;
        free(elementDefile);
    }

    return nombreDefile;
}
void afficherFile(File *file){
    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    Element *element = file->premier;

    while (element != NULL){
        printf("%d ", element->nombre);
        element = element->suivant;
    }

    printf("\n");
}
int main(){
    File *maFile = initialiser();

    enfiler(maFile, 4);
    enfiler(maFile, 8);
    enfiler(maFile, 15);
    enfiler(maFile, 16);
    enfiler(maFile, 23);
    enfiler(maFile, 42);

    printf("\nEtat de la file :\n");
    afficherFile(maFile);

    printf("\nJe defile %d\n", defiler(maFile));
    printf("Je defile %d\n", defiler(maFile));

    printf("\nEtat de la file :\n");
    afficherFile(maFile);
}