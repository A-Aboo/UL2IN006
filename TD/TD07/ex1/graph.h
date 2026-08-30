#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arete
{
    int u;
    int v;
    double dist;
} Arete;

typedef struct elementListeA
{
    Arete *a;
    struct elementListeA *suiv;
} ElementListeA;

typedef ElementListeA *ListeA;

typedef struct sommet
{
    int numS;
    char *nomVille;
    float x;
    float y;
    ListeA liste;
} Sommet;

typedef struct graphe
{
    int nbSom;
    Sommet **tabS;
} Graphe;

Graphe *creerGraphe(int n);
void majCoordonnee(Graphe *g, int i, char *nom, float x, float y);

Arete *creerArete(int u, int v, double dist);
void insererEnTeteListeA(ListeA *p_LA, Arete *a);
void ajoutArete(Graphe *g, int i, int j, double dist);

void afficherListeA(ListeA la);
void afficherGraphe(Graphe *g);

void desalloueListeA(ListeA la);
void desalloueGraphe(Graphe *g);

#endif