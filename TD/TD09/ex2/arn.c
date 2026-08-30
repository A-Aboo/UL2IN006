#include "arn.h"

ARNtree *creerNoeud(int valeur, Couleur co)
{
    ARNtree *t = (ARNtree *)malloc(sizeof(ARNtree));

    t->valeur = valeur;
    t->co = co;
    t->fg = NULL;
    t->fd = NULL;
    t->pere = NULL;

    return t;
}

/* Q2.2 */
int nbRouges(ARNtree *t)
{
    if (t == NULL)
        return 0;

    int nb = nbRouges(t->fg) + nbRouges(t->fd);

    if (t->co == rouge)
        nb += 1;

    return nb;
}

/* Q2.3 */
int minABR(ARNtree *t)
{
    if (t == NULL)
        return -1;
    if (t->fg == NULL)
        return t->valeur;

    return minABR(t->fg);
}

int maxABR(ARNtree *t)
{
    if (t == NULL)
        return -1;
    if (t->fd == NULL)
        return t->valeur;

    return maxABR(t->fd);
}

int checkABR(ARNtree *t)
{
    if (t == NULL)
        return 1;

    if (t->fg != NULL){
        if (checkABR(t->fg) == 0)
            return 0;
        if (maxABR(t->fg) >= t->valeur)
            return 0;
    }

    if (t->fd != NULL){
        if (checkABR(t->fd) == 0)
            return 0;
        if (minABR(t->fd) <= t->valeur)
            return 0;
    }

    return 1;
}

int verifARNrec(ARNtree *subt, int nbNoeudNoir, int hauteurNoire)
{
    if (subt == NULL)
        return nbNoeudNoir == hauteurNoire;

    if (subt->co == noir)
        return verifARNrec(subt->fg, nbNoeudNoir + 1, hauteurNoire)
            && verifARNrec(subt->fd, nbNoeudNoir + 1, hauteurNoire);

    if (subt->fg != NULL && subt->fg->co == rouge)
        return 0;
    if (subt->fd != NULL && subt->fd->co == rouge)
        return 0;

    return verifARNrec(subt->fg, nbNoeudNoir, hauteurNoire)
        && verifARNrec(subt->fd, nbNoeudNoir, hauteurNoire);
}

int main(void)
{
    ARNtree *r = creerNoeud(17, noir);

    r->fg = creerNoeud(7, noir);
    r->fd = creerNoeud(22, noir);
    r->fg->fd = creerNoeud(11, rouge);
    r->fd->fg = creerNoeud(21, rouge);

    printf("noeuds rouges : %d\n", nbRouges(r));
    printf("ABR : %d\n", checkABR(r));
    printf("ARN : %d\n", verifARNrec(r, 0, 2));

    return 0;
}
