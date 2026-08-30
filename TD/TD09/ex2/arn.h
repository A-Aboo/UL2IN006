#ifndef ARN_H
#define ARN_H

#include <stdio.h>
#include <stdlib.h>

/* Q2.1 */
typedef enum {rouge, noir} Couleur;

typedef struct arn
{
    int valeur;
    Couleur co;
    struct arn *fg;
    struct arn *fd;
    struct arn *pere;
} ARNtree;

ARNtree *creerNoeud(int valeur, Couleur co);

/* Q2.2 */
int nbRouges(ARNtree *t);

/* Q2.3 */
int minABR(ARNtree *t);
int maxABR(ARNtree *t);
int checkABR(ARNtree *t);
int verifARNrec(ARNtree *subt, int nbNoeudNoir, int hauteurNoire);

#endif
