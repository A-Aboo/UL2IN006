#include "graphe.h"

void initFile(File *f)
{
    f->tete = NULL;
    f->queue = NULL;
}

int estFileVide(File f)
{
    return f.tete == NULL;
}

void enfile(File *f, int donnee)
{
    ElemFile *e = (ElemFile *)malloc(sizeof(ElemFile));

    e->val = donnee;
    e->suiv = NULL;

    if (f->queue == NULL)
        f->tete = e;
    else
        f->queue->suiv = e;

    f->queue = e;
}

int defile(File *f)
{
    ElemFile *e = f->tete;
    int val = e->val;

    f->tete = e->suiv;
    if (f->tete == NULL)
        f->queue = NULL;

    free(e);
    return val;
}

/* Q2.1 */
void creeGraphe(Graphe *G, int n)
{
    G->nbsom = n;
    G->t_som = (Sommet *)malloc(n * sizeof(Sommet));

    for (int i = 0; i < n; i++){
        G->t_som[i].u = i;
        G->t_som[i].L_succ = NULL;
        G->t_som[i].L_prec = NULL;
    }
}

void ajoutArc(Graphe *G, int i, int j)
{
    Arc *a = (Arc *)malloc(sizeof(Arc));
    a->v = j;
    a->suiv = G->t_som[i].L_succ;
    G->t_som[i].L_succ = a;

    Arc *b = (Arc *)malloc(sizeof(Arc));
    b->v = i;
    b->suiv = G->t_som[j].L_prec;
    G->t_som[j].L_prec = b;
}

void afficheGraphe(Graphe *G)
{
    printf("\nGraphe :\n");

    for (int i = 0; i < G->nbsom; i++){
        printf("%d -> ", i);

        Arc *a = G->t_som[i].L_succ;
        while (a != NULL){
            printf("%d ", a->v);
            a = a->suiv;
        }
        printf("\n");
    }
}

/* Q2.3 */
void liste_descendants(Graphe *G, int r, int *marquage)
{
    File f;
    initFile(&f);

    for (int i = 0; i < G->nbsom; i++)
        marquage[i] = 0;

    marquage[r] = 1;
    enfile(&f, r);

    while (!estFileVide(f)){
        int s = defile(&f);

        Arc *a = G->t_som[s].L_succ;
        while (a != NULL){
            if (marquage[a->v] == 0){
                marquage[a->v] = 1;
                enfile(&f, a->v);
            }
            a = a->suiv;
        }
    }
}

void liste_ascendants(Graphe *G, int r, int *marquage)
{
    File f;
    initFile(&f);

    for (int i = 0; i < G->nbsom; i++)
        marquage[i] = 0;

    marquage[r] = 1;
    enfile(&f, r);

    while (!estFileVide(f)){
        int s = defile(&f);

        Arc *a = G->t_som[s].L_prec;
        while (a != NULL){
            if (marquage[a->v] == 0){
                marquage[a->v] = 1;
                enfile(&f, a->v);
            }
            a = a->suiv;
        }
    }
}

/* Q2.4 */
void composantes_fortement_connexes(Graphe *G, int *CFC)
{
    int n = G->nbsom;
    int *desc = (int *)malloc(n * sizeof(int));
    int *asc = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        CFC[i] = -1;

    for (int i = 0; i < n; i++){
        if (CFC[i] != -1)
            continue;

        liste_descendants(G, i, desc);
        liste_ascendants(G, i, asc);

        for (int j = 0; j < n; j++){
            if (desc[j] == 1 && asc[j] == 1)
                CFC[j] = i;
        }
    }

    free(desc);
    free(asc);
}

void desalloueGraphe(Graphe *G)
{
    for (int i = 0; i < G->nbsom; i++){
        Arc *a = G->t_som[i].L_succ;
        while (a != NULL){
            Arc *tmp = a;
            a = a->suiv;
            free(tmp);
        }

        a = G->t_som[i].L_prec;
        while (a != NULL){
            Arc *tmp = a;
            a = a->suiv;
            free(tmp);
        }
    }

    free(G->t_som);
}

int main(void)
{
    Graphe G;
    creeGraphe(&G, 8);

    ajoutArc(&G, 0, 1);
    ajoutArc(&G, 1, 2);
    ajoutArc(&G, 2, 0);
    ajoutArc(&G, 1, 3);
    ajoutArc(&G, 3, 5);
    ajoutArc(&G, 5, 6);
    ajoutArc(&G, 6, 7);
    ajoutArc(&G, 7, 3);
    ajoutArc(&G, 4, 3);
    ajoutArc(&G, 4, 6);
    ajoutArc(&G, 2, 7);

    afficheGraphe(&G);

    int CFC[8];
    composantes_fortement_connexes(&G, CFC);
    for (int i = 0; i < 8; i++)
        printf("sommet %d : CFC%d\n", i, CFC[i]);

    desalloueGraphe(&G);

    return 0;
}
