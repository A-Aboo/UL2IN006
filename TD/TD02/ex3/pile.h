#ifndef PILE_H
#define PILE_H

#include <stdlib.h>

#define MAX 100

typedef struct pile
{
    int tab[MAX];
    int top;
} Pile;

Pile *creerPile(void);
int pileVide(Pile *p);
void empile(Pile *p, int valeur);
int depile(Pile *p);

#endif