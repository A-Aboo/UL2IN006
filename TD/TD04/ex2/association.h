#ifndef ASSOCIATION_H
#define ASSOCIATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel
{
    char *nom;
    struct cel *suivant;
} Cellule;

typedef struct asso
{
    char *nom;
    Cellule *lesMembres;
} Association;

typedef struct maison
{
    Association *assoc;
    struct maison *suiv;
} MaisonDesAssociations;

Association *creerAssociation(char *nom);
void ajouterPersonne(Association *A, char *nom);
void supprimerPersonne(Association *A, char *nom);

MaisonDesAssociations *creerMaisonAssoc(void);
void ajouterAssociation(MaisonDesAssociations **p_M, Association *A);
void supprimerAssociation(MaisonDesAssociations **p_M, Association *A);

void libererAssociation(Association *A);
void libererMaison(MaisonDesAssociations *M);

#endif