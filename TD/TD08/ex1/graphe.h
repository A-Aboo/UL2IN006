#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct cellule
{
    int v;
    struct cellule *suiv;
} Cellule;

typedef struct
{
    int nbsom;
    Cellule **tabS;
} GrapheSimple;

/* Q1.2 */
void cree_graphe(GrapheSimple *G, int n);
void ajoute_lien(GrapheSimple *G, int i, int j);
void ajoute_arete(GrapheSimple *G, int i, int j);
void aff_graphe(GrapheSimple *G);

/* Q1.3 */
void aff_parcours_1(GrapheSimple *G, int r);

/* Q1.4 */
void aff_parcours_2(GrapheSimple *G, int r, int pere);

/* Q1.6 */
void aff_parcours_3(GrapheSimple *G, int r, int *visit);

/* Q1.7 */
int circuit_depuis(GrapheSimple *G, int r, int *visit);

/* Q1.8 */
int existe_circuit(GrapheSimple *G);

/* Q1.9 */
int circuit_pred(GrapheSimple *G, int *pred, int *k, int *l);

/* Q1.10 */
void aff_circuit(int *pred, int k, int l);

/* Q1.11 */
int cycle_non_oriente(GrapheSimple *G);

void desalloue_graphe(GrapheSimple *G);

#endif
