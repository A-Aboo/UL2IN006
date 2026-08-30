#ifndef HACHAGE_H
#define HACHAGE_H

#include <stdio.h>
#include <stdlib.h>

/* Q4.1 */
typedef struct _List
{
    int val;
    int cle;
    struct _List *suiv;
} List;

typedef struct _T_hache
{
    int nb_max;
    List **T_List;
    int nb_elem;
} T_hache;

T_hache *cree_Thache(int n);

/* Q4.2 */
int hache(int cle, int nb_max);
void inserer(T_hache *TableHachage, int val, int cle);

/* Q4.4 */
int supprime_elem(T_hache *T, int cle);

void affiche_l(List *l, int nb_max);
void affiche_T(T_hache *T);

#endif
