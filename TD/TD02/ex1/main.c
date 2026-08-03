/*
  compile this way :
  gcc post.c ../ex1/liste.c main.c -o poste
 
 post.c uses the list functions defined in ../ex1/liste.c.
*/









#include <stdio.h>
#include "liste.h"

int main(void)
{
    Liste *liste;

    liste = creerListe();
    if (liste == NULL)
        return 1;

    insererEnTete(liste, 10);
    insererEnFin(liste, 20);
    insererEnFin(liste, 30);

    afficher(liste);

    desalloueListe(liste);
    return 0;
}