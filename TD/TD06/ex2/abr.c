#include "abr.h"

int AB_hauteur(ABR ab)
{
    if (ab == NULL)
        return -1;

    return ab->hauteur;
}

int max(int a, int b)
{
    if (a > b)
        return a;

    return b;
}

void majHauteur(ABR ab)
{
    if (ab != NULL)
    {
        ab->hauteur =
            1 + max(AB_hauteur(ab->fg), AB_hauteur(ab->fd));
    }
}

void rotationDroite(ABR *ab)
{

    Noeud *r = *ab;
    Noeud *g = r->fg;
    Noeud *v = g->fd;

    r->fg = v;
    g->fd = r;
    *ab = g;

    majHauteur(r);
    majHauteur(g);
}

void rotationGauche(ABR *ab)
{

    Noeud *g = *ab;
    Noeud *r = g->fd;
    Noeud *v = r->fg;

    g->fd = v;
    r->fg = g;
    *ab = r;

    majHauteur(g);
    majHauteur(r);
}

void insererElem_avec_eq(ABR *ab, int val)
{
    if (*ab ==NULL){
        Noeud *n= malloc(sizeof(Noeud));

        if (n== NULL)
            return;

        n->valeur = val;
        n->hauteur = 0;
        n->fg = NULL;
        n->fd = NULL;

        *ab =n;
        return;
    }

    if (val <(*ab)->valeur)
        insererElem_avec_eq(&(*ab)->fg, val);
    else if (val > (*ab)->valeur)
        insererElem_avec_eq(&(*ab)->fd, val);
    else
        return;

    majHauteur(*ab);

    int hfg = AB_hauteur((*ab)->fg);
    int hfd = AB_hauteur((*ab)->fd);

    if (hfg - hfd == 2){
        if (AB_hauteur((*ab)->fg->fg)< AB_hauteur((*ab)->fg->fd)){
            rotationGauche(&(*ab)->fg);
        }
        rotationDroite(ab);
    }else if (hfg - hfd == -2){
        if (AB_hauteur((*ab)->fd->fd)< AB_hauteur((*ab)->fd->fg)){
            rotationDroite(&(*ab)->fd);
        }
        rotationGauche(ab);
    }
}


/*
Q2.1 — 

En ajoutant 1, 2, 3, 4, 5, puis 6, on obtient :
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
          
Q2.4 — Rotation droite

Avant :

        r
       / \
      g   D
     / \
    G   v

Après :

        g
       / \
      G   r
         / \
        v   D


Q2.5 — Rotation gauche

Avant :

      g
     / \
    G   r
       / \
      v   D

Après :

        r
       / \
      g   D
     / \
    G   v


Q2.7 — 


        4
       / \
      2   5
     / \   \
    1   3   6
*/