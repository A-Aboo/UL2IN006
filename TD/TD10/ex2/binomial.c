#include "binomial.h"

/* Q2.2.5 */
void unionAB(ArbreBinomial *A1, ArbreBinomial *A2)
{
    A2->pere = A1;
    A2->frere_a_droite = A1->fils_gauche;
    A1->fils_gauche = A2;
    A1->degre += 1;
}

void initTB(TasBinomial T)
{
    for (int i = 0; i < 10; i++)
        T[i] = NULL;
}

int min(TasBinomial t)
{
    int m = INT_MAX;

    for (int i = 0; i < 10; i++){
        if (t[i] != NULL){
            if (t[i]->valeur < m)
                m = t[i]->valeur;
        }
    }

    return m;
}

ArbreBinomial *unionAB_Tas(ArbreBinomial *B1, ArbreBinomial *B2)
{
    if (B1 == NULL)
        return B2;
    if (B2 == NULL)
        return B1;

    if (B1->valeur < B2->valeur){
        unionAB(B1, B2);
        return B1;
    }
    else {
        unionAB(B2, B1);
        return B2;
    }
}

void unionTB(TasBinomial T1, TasBinomial T2)
{
    ArbreBinomial *report = NULL;

    for (int i = 0; i < 10; i++){
        ArbreBinomial *t[3];
        int n = 0;

        if (T1[i] != NULL)
            t[n++] = T1[i];
        if (T2[i] != NULL)
            t[n++] = T2[i];
        if (report != NULL)
            t[n++] = report;

        T1[i] = NULL;
        report = NULL;

        if (n == 1 || n == 3)
            T1[i] = t[n - 1];
        if (n >= 2)
            report = unionAB_Tas(t[0], t[1]);
    }
}

void insereTB(TasBinomial T1, int val)
{
    TasBinomial s;

    s[0] = (ArbreBinomial *)malloc(sizeof(ArbreBinomial));
    for (int i = 1; i < 10; i++)
        s[i] = NULL;

    s[0]->pere = NULL;
    s[0]->frere_a_droite = NULL;
    s[0]->fils_gauche = NULL;
    s[0]->valeur = val;
    s[0]->degre = 0;

    unionTB(T1, s);
}

int main(void)
{
    TasBinomial T;
    int t[] = {1, 5, 22, 11, 19, 3, 4, 7};

    initTB(T);

    for (int i = 0; i < 8; i++)
        insereTB(T, t[i]);

    for (int i = 0; i < 10; i++)
        if (T[i] != NULL)
            printf("B%d : racine %d\n", i, T[i]->valeur);

    printf("min : %d\n", min(T));

    return 0;
}
