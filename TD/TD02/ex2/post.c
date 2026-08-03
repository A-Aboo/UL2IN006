#include "post.h"



Poste* creerGuichets(int nb){
    Poste* P = (Poste*) malloc(sizeof(Poste));
    P->nb = nb;
    P->tabGuichets = (Liste*) malloc(nb*sizeof(Liste));
    for(int i=0; i<nb; i++) initialiserListe(&(P->tabGuichets[i]));
    return P;
}


void afficherPoste(Poste* P){
    int i;
    printf("Bureau de poste = %d guichets\n", P->nb);
    for(i=0; i<P->nb; i++){
        if(listeVide(&(P->tabGuichets[i])))
            printf("\t Guichet numéro %d : Vide\n" , i);
        else {
            printf("\t Guichet numéro %d : ",i);
            afficher(&(P->tabGuichets[i]));
        }
    }
}


void ajouterAuGuichet(Poste* P, int noGuichet, int noPersonne){
    insererEnTete(&(P->tabGuichets[noGuichet]), noPersonne);
}

int appelerAuGuichet(Poste* P, int noGuichet){

    if(listeVide(&(P->tabGuichets[noGuichet]))) return -1;
    return supprimerFin(&(P->tabGuichets[noGuichet]));
}