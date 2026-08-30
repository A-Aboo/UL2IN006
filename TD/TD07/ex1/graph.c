#include "graph.h"



Graphe *creerGraphe(int n)
{
    Graphe *g = (Graphe *)malloc(sizeof(Graphe));
    g->tabS = (Sommet **)malloc(sizeof(Sommet *) * n);

    g->nbSom = n;

    for (int i =0; i <n; i++){
        g->tabS[i] = (Sommet *)malloc(sizeof(Sommet));
        g->tabS[i]->numS = i;
        g->tabS[i]->nomVille = NULL;
        g->tabS[i]->liste = NULL;
    }
    return g;
}


void majCoordonnee(Graphe *g, int i, char *nom, float x, float y)
{
    g->tabS[i]->nomVille = strdup(nom);
    g->tabS[i]->x = x;
    g->tabS[i]->y = y;
}

Arete *creerArete(int u, int v, double dist)
{
    Arete *a = (Arete *)malloc(sizeof(Arete));

    a->u = u;
    a->v = v;
    a->dist = dist;

    return a;
}

void insererEnTeteListeA(ListeA *p_LA, Arete *a)
{
    ElementListeA *e =(ElementListeA *)malloc(sizeof(ElementListeA));

    e->a = a;
    e->suiv = *p_LA;
    *p_LA = e;
}

void ajoutArete(Graphe *g, int i, int j, double dist)
{

    Arete *a = creerArete(i, j, dist);
    insererEnTeteListeA(&(g->tabS[i]->liste), a);
    insererEnTeteListeA(&(g->tabS[j]->liste), a);
}


void afficherListeA(ListeA l)
{
    while (l != NULL)
    {
        printf("{%d, %d, distance %.2f} | ",
            l->a->u, l->a->v, l->a->dist);

        l = l->suiv;
    }
}

void afficherGraphe(Graphe *g)
{
    printf("Nombre de sommets : %d\n", g->nbSom);

    for (int i = 0; i <g->nbSom; i++){
        printf("Sommet %d", g->tabS[i]->numS);

        if (g->tabS[i]->nomVille != NULL)
            printf(" (%s)", g->tabS[i]->nomVille);

        printf(" : ");

        if (g->tabS[i]->liste == NULL)
            printf("aucune route");
        else
            afficherListeA(g->tabS[i]->liste);
        printf("\n");
    }
}



void desalloueListeA(ListeA l)
{
    while (l != NULL){
        ElementListeA *tmp = l;
        l = l->suiv;
        if (tmp->a->u != -1)
            tmp->a->u = -1;
        else
            free(tmp->a);

        free(tmp);
    }
}

void desalloueGraphe(Graphe *g)
{
    for (int i = 0;i < g->nbSom;i++){
        desalloueListeA(g->tabS[i]->liste);
        free(g->tabS[i]->nomVille);
        free(g->tabS[i]);
    }

    free(g->tabS);
    free(g);
}



int main(void)
{
    Graphe *g = creerGraphe(4);

    majCoordonnee(g, 0, "A", 10, 35);
    majCoordonnee(g, 1, "B", 15, 20);
    majCoordonnee(g, 2, "C", 25, 30);
    majCoordonnee(g, 3, "D", 25, 20);

    ajoutArete(g, 0, 1, 5);
    ajoutArete(g, 0, 2, 10);

    afficherGraphe(g);

    desalloueGraphe(g);

    return 0;
}