#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

struct _cellule
{
    int v;
    struct _cellule *suiv;
};

typedef struct _cellule Cellule;

typedef struct
{
    int nbsom;
    Cellule **tabS;
} GrapheSimple;

void cree_graphe(GrapheSimple *G, int n);
void ajoute_arete(GrapheSimple *G, int i, int j);

/* Q1.1 */
void un_parcours(GrapheSimple *G, int r, int *T, int num_cc);
int *composantes_connexes(GrapheSimple *G);

#endif
