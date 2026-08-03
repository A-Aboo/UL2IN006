

#include "liste.h"

//Q1.2


Element *creerElement(int valeur)
{
    Element *n = malloc(sizeof(Element) );

    n-> valeur = valeur;
    n->precedent = NULL ;
    n->suivant = NULL ;

    return n;
}


//Q1.3

void initialiserListe(Liste *liste)
{
    if (liste == NULL)
        return;

    liste->premier = NULL;
    liste->dernier = NULL;
}

Liste *creerListe(void)
{
    Liste *liste = malloc(sizeof (Liste));

    initialiserListe(liste);
    return liste;
}

int listeVide(Liste *liste)
{
    if (liste == NULL)
        return 1;

    return liste->premier == NULL;
}


//Q1.4

void insererEnTete(Liste *liste, int valeur)
{
    Element *n = creerElement(valeur);

    n->suivant = liste->premier;

    if (listeVide(liste))
        liste->dernier = n;
    else
        liste->premier->precedent = n;

    liste->premier = n;
}

//Q1.5

void insererEnFin(Liste *liste, int valeur)
{
    Element *n = creerElement(valeur);

    n->precedent = liste->dernier;

    if (listeVide(liste))
        liste->premier = n;
    else
        liste->dernier->suivant = n;

    liste->dernier = n;
}


// q1.6

void afficher(Liste *liste)
{
    Element *link= liste->dernier;

    while (link != NULL)
    {
        printf("%d", link->valeur);

        if (link->precedent != NULL)
            printf(" ");

        link = link->precedent;
    }

    printf("\n");
}

//Q1.7

Element *rechercher(Liste *liste, int valeur)
{
    Element *link = liste->premier;

    while ( link != NULL)
    {
        if (link->valeur == valeur)
            return link;

        link = link-> suivant ;
     }

   return NULL;
}

//Q1.8
void supprimerElement(Liste *liste, Element *element)
{
    if (liste == NULL || element == NULL)
        return;

    if (element->precedent != NULL)
        element->precedent->suivant = element->suivant;
    else
        liste->premier = element->suivant;

    if (element->suivant != NULL)
        element->suivant->precedent = element->precedent;
    else
        liste->dernier = element->precedent;

    free(element);
}

// Q1.9
int supprimerTete(Liste *liste)
{
    int valeur = liste->premier->valeur;
    supprimerElement(liste, liste->premier);

    return valeur;
}

int supprimerFin(Liste *liste)
{
    int valeur= liste->dernier->valeur;
    supprimerElement(liste, liste->dernier);

    return valeur;
}


void desalloueListe(Liste *liste)
{
    Element *link =  liste->premier;
    Element *suivant;
    while (link != NULL)
    {
        suivant = link->suivant;
        free(link);
        link = suivant;
    }

    free(liste);
}

