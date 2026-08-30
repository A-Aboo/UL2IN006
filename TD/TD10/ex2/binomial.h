#ifndef BINOMIAL_H
#define BINOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Q2.2.4 */
typedef struct t_noeud
{
    struct t_noeud *pere;
    struct t_noeud *frere_a_droite;
    struct t_noeud *fils_gauche;
    int valeur;
    int degre;
} ArbreBinomial;

/* Q2.2.5 */
void unionAB(ArbreBinomial *A1, ArbreBinomial *A2);

typedef ArbreBinomial *TasBinomial[10];

void initTB(TasBinomial T);

int min(TasBinomial t);

ArbreBinomial *unionAB_Tas(ArbreBinomial *B1, ArbreBinomial *B2);
void unionTB(TasBinomial T1, TasBinomial T2);
void insereTB(TasBinomial T1, int val);

#endif
