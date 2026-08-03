#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>
typedef struct s_element
{
    int valeur;
    struct s_element *precedent;
    struct s_element *suivant;
} Element;

typedef struct s_liste
{
    Element *premier;
    Element *dernier;
} Liste;

Element *creerElement(int valeur);
void initialiserListe(Liste *liste);
Liste *creerListe(void);
int listeVide(Liste *liste);
void insererEnTete(Liste *liste, int valeur);
void insererEnFin(Liste *liste, int valeur);
void afficher(Liste *liste);
Element *rechercher(Liste *liste, int valeur);
void supprimerElement(Liste *liste, Element *element);
int supprimerTete(Liste *liste);
int supprimerFin(Liste *liste);
void desalloueListe(Liste *liste);

#endif