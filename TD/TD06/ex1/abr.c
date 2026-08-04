#include "abr.h"

Noeud *rechercherValeur(ABR ab, int val)
{
    if (ab->valeur == val) return ab;
    if (val < ab->valeur) return rechercherValeur(ab->fg, val);
    return rechercherValeur(ab->fd, val);
}

void insererElem(ABR *ab, int val){
    if (*ab== NULL){
        Noeud *n =malloc(sizeof(Noeud));
        n->valeur = val;
        n->fg = NULL;
        n->fd = NULL;

        *ab = n;
        return;
    }
    if (val < (*ab)->valeur) insererElem(&(*ab)->fg, val);
    else if (val > (*ab)->valeur) insererElem(&(*ab)->fd, val);
}

void supprimer(ABR *ab, int val){
    if (val < (*ab)->valeur){
        supprimer(&(*ab)->fg, val);
    }else if (val > (*ab)->valeur){
        supprimer(&(*ab)->fd, val);
    }else{
        if ((*ab)->fd == NULL){
            Noeud *a_suppr = *ab;

            *ab = (*ab)->fg;
            free(a_suppr);
        }else if ((*ab)->fg == NULL)
        {
            Noeud *a_suppr = *ab;

            *ab = (*ab)->fd;
            free(a_suppr);
        }
        else
        {
            ABR *p_cour = &(*ab)->fg;

            while ((*p_cour)->fd != NULL)
                p_cour = &(*p_cour)->fd;

            (*ab)->valeur = (*p_cour)->valeur;
            supprimer(p_cour, (*p_cour)->valeur);
        }
    }
}