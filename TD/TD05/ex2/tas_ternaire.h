#ifndef TAS_TERNAIRE_H
#define TAS_TERNAIRE_H

#include <stdio.h>
#include <stdlib.h>

/* Q2.3 */
typedef struct
{
    int *tab;
    int taille;
    int max;
} TasTernaire;

void creerTas(TasTernaire *t, int max);
int pere(int i);
int fils(int i, int k);
void echanger(TasTernaire *t, int i, int j);
void inserer(TasTernaire *t, int val);
void afficherTas(TasTernaire *t);

/* Q2.4 */
int supprimerMin(TasTernaire *t);

#endif
