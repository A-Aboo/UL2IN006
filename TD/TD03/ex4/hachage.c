#include "hachage.h"

T_hache *cree_Thache(int n)
{
    T_hache *T = malloc(sizeof(T_hache));

    T->nb_max = n;
    T->nb_elem = 0;
    T->T_List = malloc(sizeof(List *) * n);

    for (int i = 0; i < n; i++)
        T->T_List[i] = NULL;

    return T;
}

/* Q4.2 */
int hache(int cle, int nb_max)
{
    if (cle < 0)
        cle = -cle;

    cle = cle * 31 + 7;

    return cle % nb_max;
}

void inserer(T_hache *TableHachage, int val, int cle)
{
    int index = hache(cle, TableHachage->nb_max);
    List *l = malloc(sizeof(List));

    l->cle = cle;
    l->val = val;

    l->suiv = TableHachage->T_List[index];
    TableHachage->T_List[index] = l;
    TableHachage->nb_elem += 1;
}

/* Q4.4 */
int supprime_elem(T_hache *T, int cle)
{
    int index = hache(cle, T->nb_max);
    List *elem = T->T_List[index];

    if (elem == NULL)
        return 0;

    if (elem->cle == cle){
        T->T_List[index] = elem->suiv;
        T->nb_elem -= 1;
        free(elem);
        return 1;
    }

    while (elem->suiv != NULL && elem->suiv->cle != cle)
        elem = elem->suiv;

    if (elem->suiv == NULL)
        return 0;

    List *temp = elem->suiv;
    elem->suiv = temp->suiv;
    free(temp);
    T->nb_elem -= 1;

    return 1;
}

void affiche_l(List *l, int nb_max)
{
    while (l){
        printf("[cle->%d\t val->%d\t hache->%d]", l->cle, l->val, hache(l->cle, nb_max));
        l = l->suiv;
    }
    printf("\n");
}

void affiche_T(T_hache *T)
{
    for (int i = 0; i < T->nb_max; i++)
        affiche_l(T->T_List[i], T->nb_max);
}

int main(void)
{
    T_hache *T = cree_Thache(10);

    inserer(T, 200, 28);
    inserer(T, 100, 15);
    inserer(T, 400, 51);
    inserer(T, 300, 42);
    inserer(T, 600, 79);

    affiche_T(T);

    printf("suppression cle 15 : %d\n", supprime_elem(T, 15));
    printf("nb elements : %d\n", T->nb_elem);

    return 0;
}
