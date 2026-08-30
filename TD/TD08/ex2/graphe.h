#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct arc
{
    int v;
    struct arc *suiv;
} Arc;

typedef struct sommet
{
    int u;
    Arc *L_succ;
    Arc *L_prec;
} Sommet;

typedef struct
{
    int nbsom;
    Sommet *t_som;
} Graphe;

typedef struct elemFile
{
    int val;
    struct elemFile *suiv;
} ElemFile;

typedef struct
{
    ElemFile *tete;
    ElemFile *queue;
} File;

void initFile(File *f);
int estFileVide(File f);
void enfile(File *f, int donnee);
int defile(File *f);

/* Q2.1 */
void creeGraphe(Graphe *G, int n);
void ajoutArc(Graphe *G, int i, int j);
void afficheGraphe(Graphe *G);

/* Q2.3 */
void liste_descendants(Graphe *G, int r, int *marquage);
void liste_ascendants(Graphe *G, int r, int *marquage);

/* Q2.4 */
void composantes_fortement_connexes(Graphe *G, int *CFC);

void desalloueGraphe(Graphe *G);

#endif
