#include <stdio.h>
#include "post.h"

int main(void)
{
    Poste *P = creerGuichets(3);

    ajouterAuGuichet(P, 0, 10);
    ajouterAuGuichet(P, 0, 11);
    ajouterAuGuichet(P, 1, 20);

    afficherPoste(P);

    printf("Personne appelee : %d\n", appelerAuGuichet(P, 0));

    afficherPoste(P);

    return 0;
}