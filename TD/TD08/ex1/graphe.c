#include "graphe.h"

/* Q1.2 */
void cree_graphe(GrapheSimple *G, int n)
{
    G->nbsom = n;
    G->tabS = (Cellule **)malloc(n * sizeof(Cellule *));

    for (int i = 0; i < n; i++)
        G->tabS[i] = NULL;
}

void ajoute_lien(GrapheSimple *G, int i, int j)
{
    Cellule *nouv = (Cellule *)malloc(sizeof(Cellule));

    nouv->v = j;
    nouv->suiv = G->tabS[i];
    G->tabS[i] = nouv;
}

void ajoute_arete(GrapheSimple *G, int i, int j)
{
    ajoute_lien(G, i, j);
    ajoute_lien(G, j, i);
}

void aff_graphe(GrapheSimple *G)
{
    printf("\nGraphe :\n");

    for (int i = 0; i < G->nbsom; i++){
        printf("%d : ", i);

        Cellule *cour = G->tabS[i];
        while (cour != NULL){
            printf("%d ", cour->v);
            cour = cour->suiv;
        }
        printf("\n");
    }
}

/* Q1.3 */
void aff_parcours_1(GrapheSimple *G, int r)
{
    printf("%d ", r);

    Cellule *cour = G->tabS[r];
    while (cour != NULL){
        aff_parcours_1(G, cour->v);
        cour = cour->suiv;
    }
}

/* Q1.4 */
void aff_parcours_2(GrapheSimple *G, int r, int pere)
{
    printf("%d ", r);

    Cellule *cour = G->tabS[r];
    while (cour != NULL){
        if (cour->v != pere)
            aff_parcours_2(G, cour->v, r);
        cour = cour->suiv;
    }
}

/* Q1.6 */
void aff_parcours_3(GrapheSimple *G, int r, int *visit)
{
    visit[r] = 1;
    printf("%d ", r);

    Cellule *cour = G->tabS[r];
    while (cour != NULL){
        if (visit[cour->v] == 0)
            aff_parcours_3(G, cour->v, visit);
        cour = cour->suiv;
    }
}

/* Q1.7 */
int circuit_depuis(GrapheSimple *G, int r, int *visit)
{
    visit[r] = 1;

    Cellule *cour = G->tabS[r];
    while (cour != NULL){
        int v = cour->v;

        if (visit[v] == 1)
            return 1;
        if (visit[v] == 0 && circuit_depuis(G, v, visit))
            return 1;

        cour = cour->suiv;
    }

    visit[r] = 2;
    return 0;
}

/* Q1.8 */
int existe_circuit(GrapheSimple *G)
{
    int *visit = (int *)calloc(G->nbsom, sizeof(int));

    for (int i = 0; i < G->nbsom; i++){
        if (visit[i] == 0 && circuit_depuis(G, i, visit)){
            free(visit);
            return 1;
        }
    }

    free(visit);
    return 0;
}

/* Q1.9 */
static int circuit_pred_rec(GrapheSimple *G, int r, int *visit, int *pred,
                            int *k, int *l)
{
    visit[r] = 1;

    Cellule *cour = G->tabS[r];
    while (cour != NULL){
        int v = cour->v;

        if (visit[v] == 1){
            *k = r;
            *l = v;
            return 1;
        }
        if (visit[v] == 0){
            pred[v] = r;
            if (circuit_pred_rec(G, v, visit, pred, k, l))
                return 1;
        }

        cour = cour->suiv;
    }

    visit[r] = 2;
    return 0;
}

int circuit_pred(GrapheSimple *G, int *pred, int *k, int *l)
{
    int *visit = (int *)calloc(G->nbsom, sizeof(int));

    for (int i = 0; i < G->nbsom; i++)
        pred[i] = -1;

    for (int i = 0; i < G->nbsom; i++){
        if (visit[i] == 0 && circuit_pred_rec(G, i, visit, pred, k, l)){
            free(visit);
            return 1;
        }
    }

    free(visit);
    return 0;
}

/* Q1.10 */
void aff_circuit(int *pred, int k, int l)
{
    int tab[100];
    int n = 0;
    int s = k;

    tab[n] = s;
    n++;

    while (s != l){
        s = pred[s];
        tab[n] = s;
        n++;
    }

    printf("Circuit : ");
    for (int i = n - 1; i >= 0; i--)
        printf("%d -> ", tab[i]);
    printf("%d\n", l);
}

/* Q1.11 */
static int cycle_rec(GrapheSimple *G, int r, int pere, int *visit)
{
    visit[r] = 1;

    Cellule *cour = G->tabS[r];
    while (cour != NULL){
        int v = cour->v;

        if (v != pere){
            if (visit[v] == 1)
                return 1;
            if (visit[v] == 0 && cycle_rec(G, v, r, visit))
                return 1;
        }

        cour = cour->suiv;
    }

    visit[r] = 2;
    return 0;
}

int cycle_non_oriente(GrapheSimple *G)
{
    int *visit = (int *)calloc(G->nbsom, sizeof(int));

    for (int i = 0; i < G->nbsom; i++){
        if (visit[i] == 0 && cycle_rec(G, i, -1, visit)){
            free(visit);
            return 1;
        }
    }

    free(visit);
    return 0;
}

void desalloue_graphe(GrapheSimple *G)
{
    for (int i = 0; i < G->nbsom; i++){
        Cellule *cour = G->tabS[i];

        while (cour != NULL){
            Cellule *tmp = cour;
            cour = cour->suiv;
            free(tmp);
        }
    }

    free(G->tabS);
}

int main(void)
{
    GrapheSimple G1, G2, G3, G4;

    cree_graphe(&G1, 6);
    ajoute_lien(&G1, 0, 1);
    ajoute_lien(&G1, 0, 4);
    ajoute_lien(&G1, 1, 2);
    ajoute_lien(&G1, 1, 3);
    ajoute_lien(&G1, 1, 5);

    cree_graphe(&G2, 6);
    ajoute_arete(&G2, 0, 1);
    ajoute_arete(&G2, 0, 4);
    ajoute_arete(&G2, 1, 2);
    ajoute_arete(&G2, 1, 3);
    ajoute_arete(&G2, 1, 5);

    cree_graphe(&G3, 6);
    ajoute_lien(&G3, 0, 1);
    ajoute_lien(&G3, 0, 4);
    ajoute_lien(&G3, 1, 2);
    ajoute_lien(&G3, 1, 3);
    ajoute_lien(&G3, 1, 5);
    ajoute_lien(&G3, 3, 4);
    ajoute_lien(&G3, 4, 5);
    ajoute_lien(&G3, 5, 3);
    ajoute_lien(&G3, 2, 3);

    cree_graphe(&G4, 6);
    ajoute_arete(&G4, 0, 1);
    ajoute_arete(&G4, 0, 4);
    ajoute_arete(&G4, 1, 2);
    ajoute_arete(&G4, 1, 3);
    ajoute_arete(&G4, 1, 5);
    ajoute_arete(&G4, 3, 4);
    ajoute_arete(&G4, 4, 5);
    ajoute_arete(&G4, 5, 3);
    ajoute_arete(&G4, 2, 3);

    aff_graphe(&G1);
    aff_graphe(&G2);
    aff_graphe(&G3);
    aff_graphe(&G4);

    printf("\nQ1.3 parcours_1 sur G1 : ");
    aff_parcours_1(&G1, 0);
    printf("\n");

    printf("\nQ1.6 parcours_3 sur G4 : ");
    int visit[6] = {0};
    aff_parcours_3(&G4, 0, visit);
    printf("\n");

    printf("\nQ1.8 circuit dans G1 : %d\n", existe_circuit(&G1));
    printf("Q1.8 circuit dans G3 : %d\n", existe_circuit(&G3));

    int pred[6], k, l;
    printf("\nQ1.10 ");
    if (circuit_pred(&G3, pred, &k, &l))
        aff_circuit(pred, k, l);

    printf("\nQ1.11 circuit sur G2 : %d\n", existe_circuit(&G2));
    printf("Q1.11 cycle sur G2 : %d\n", cycle_non_oriente(&G2));
    printf("Q1.11 cycle sur G4 : %d\n", cycle_non_oriente(&G4));

    desalloue_graphe(&G1);
    desalloue_graphe(&G2);
    desalloue_graphe(&G3);
    desalloue_graphe(&G4);

    return 0;
}
