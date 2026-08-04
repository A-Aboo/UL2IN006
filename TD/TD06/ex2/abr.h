#ifndef ABR_H
#define ABR_H

#include <stdlib.h>

typedef struct noeud
{
    int valeur;
    int hauteur;
    struct noeud *fg;
    struct noeud *fd;
} Noeud;

typedef Noeud *ABR;

int AB_hauteur(ABR ab);
int max(int a, int b);
void majHauteur(ABR ab);
void rotationDroite(ABR *ab);
void rotationGauche(ABR *ab);
void insererElem_avec_eq(ABR *ab, int val);

#endif