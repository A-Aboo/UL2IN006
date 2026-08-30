#include "tas_ternaire.h"

/* Q2.3 */
void creerTas(TasTernaire *t, int max)
{
    t->tab = (int *)malloc((max + 1) * sizeof(int));
    t->taille = 0;
    t->max = max;
}

int pere(int i)
{
    return (i + 1) / 3;
}

int fils(int i, int k)
{
    return 3 * i - 1 + k;
}

void echanger(TasTernaire *t, int i, int j)
{
    int tmp = t->tab[i];
    t->tab[i] = t->tab[j];
    t->tab[j] = tmp;
}

void inserer(TasTernaire *t, int val)
{
    t->taille++;
    t->tab[t->taille] = val;

    int i = t->taille;
    while (i > 1 && t->tab[pere(i)] > t->tab[i]){
        echanger(t, pere(i), i);
        i = pere(i);
    }
}

void afficherTas(TasTernaire *t)
{
    for (int i = 1; i <= t->taille; i++)
        printf("%d ", t->tab[i]);
    printf("\n");
}

/* Q2.4 */
int supprimerMin(TasTernaire *t)
{
    int min = t->tab[1];

    t->tab[1] = t->tab[t->taille];
    t->taille--;

    int i = 1;
    while (fils(i, 0) <= t->taille){
        int m = fils(i, 0);

        for (int k = 1; k < 3; k++){
            int f = fils(i, k);
            if (f <= t->taille && t->tab[f] < t->tab[m])
                m = f;
        }

        if (t->tab[i] <= t->tab[m])
            break;

        echanger(t, i, m);
        i = m;
    }

    return min;
}

int main(void)
{
    TasTernaire t;
    int v[] = {3, 6, 1, 13, 17, 18, 2};

    creerTas(&t, 20);

    for (int i = 0; i < 7; i++)
        inserer(&t, v[i]);

    afficherTas(&t);

    printf("min supprime : %d\n", supprimerMin(&t));
    afficherTas(&t);

    free(t.tab);

    return 0;
}
