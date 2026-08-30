#include "graphe.h"

void cree_graphe(GrapheSimple *G, int n)
{
    G->nbsom = n;
    G->tabS = (Cellule **)malloc(n * sizeof(Cellule *));

    for (int i = 0; i < n; i++)
        G->tabS[i] = NULL;
}

void ajoute_arete(GrapheSimple *G, int i, int j)
{
    Cellule *a = (Cellule *)malloc(sizeof(Cellule));
    a->v = j;
    a->suiv = G->tabS[i];
    G->tabS[i] = a;

    Cellule *b = (Cellule *)malloc(sizeof(Cellule));
    b->v = i;
    b->suiv = G->tabS[j];
    G->tabS[j] = b;
}

/* Q1.1 */
void un_parcours(GrapheSimple *G, int r, int *T, int num_cc)
{
    T[r] = num_cc;

    Cellule *cour = G->tabS[r];
    while (cour != NULL){
        int v = cour->v;

        if (T[v] == 0)
            un_parcours(G, v, T, num_cc);

        cour = cour->suiv;
    }
}

int *composantes_connexes(GrapheSimple *G)
{
    int *T = (int *)malloc(G->nbsom * sizeof(int));

    for (int i = 0; i < G->nbsom; i++)
        T[i] = 0;

    int r = 0;
    int num_cc = 1;

    while (r < G->nbsom){
        un_parcours(G, r, T, num_cc);

        while (r < G->nbsom && T[r] != 0)
            r++;

        num_cc += 1;
    }

    return T;
}

int main(void)
{
    GrapheSimple G;

    cree_graphe(&G, 6);
    ajoute_arete(&G, 0, 1);
    ajoute_arete(&G, 1, 2);
    ajoute_arete(&G, 3, 4);

    int *T = composantes_connexes(&G);
    for (int i = 0; i < 6; i++)
        printf("sommet %d : cc %d\n", i, T[i]);

    free(T);

    return 0;
}
