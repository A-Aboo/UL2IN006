#ifndef POST_H
#define POST_H

#include <stdio.h>
#include <stdlib.h>
#include "../ex1/liste.h"

typedef struct poste
{
    int nb;
    Liste *tabGuichets;
} Poste;

Poste *creerGuichets(int nb);
void afficherPoste(Poste *P);
void ajouterAuGuichet(Poste *P, int noGuichet, int noPersonne);
int appelerAuGuichet(Poste *P, int noGuichet);

#endif