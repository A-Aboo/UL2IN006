#ifndef FORMATION_H
#define FORMATION_H

#include <stdio.h>
#include <stdlib.h>

typedef struct formation Formation;

typedef struct cellule
{
    Formation *f;
    struct cellule *suiv;
} Cellule;

struct formation
{
    char *nom;
    int nbheures;
    Cellule *liste;
};

typedef struct catalogue
{
    int M;
    int nb_formations;
    Formation **T;
} Catalogue;

int nb_heures_total(Formation *F);
void afficher_avec_decalage(Formation *F, int decal);
void afficher_formation(Formation *F);
void afficher_catalogue(Catalogue *C);
int contient(Formation *F, Formation *cherche);
void ajouter_formation(Formation *destination, Formation *ajout);

#endif