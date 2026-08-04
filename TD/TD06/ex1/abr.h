#ifndef ABR_H
#define ABR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noeud
{
    int valeur;
    struct noeud *fg;
    struct noeud *fd;
} Noeud;

typedef Noeud *ABR;

Noeud *rechercherValeur(ABR ab, int val);
void insererElem(ABR *ab, int val);
void supprimer(ABR *ab, int val);

#endif