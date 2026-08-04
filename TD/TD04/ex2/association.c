#include "association.h"


Association *creerAssociation(char *nom)
{
    Association *A = malloc(sizeof(Association));
    A->nom = strdup(nom);
    A->lesMembres = NULL;
    return A;
}

void ajouterPersonne(Association *A, char *nom){
    Cellule *c = malloc(sizeof(Cellule));
    c->nom = strdup(nom);
    c->suivant = A->lesMembres;
    A->lesMembres = c;
}

void supprimerPersonne(Association *A, char *nom)
{
    Cellule *cour = A->lesMembres;
    if (strcmp(cour->nom, nom)== 0){
        A->lesMembres = cour->suivant;
        free(cour->nom);
        free(cour);
        return;
    }

    while (cour->suivant != NULL && strcmp(cour->suivant->nom, nom) != 0){
        cour = cour->suivant;}
    if (cour->suivant != NULL){
        Cellule *a_suppr = cour->suivant;
        cour->suivant = a_suppr->suivant;
        free(a_suppr->nom);
        free(a_suppr);
    }
}

MaisonDesAssociations *creerMaisonAssoc(void)
{
    return NULL;}

void ajouterAssociation(MaisonDesAssociations **p_M, Association *A)
{

    MaisonDesAssociations *nouveau =malloc(sizeof(MaisonDesAssociations));
    nouveau->assoc = A;
    nouveau->suiv = *p_M;
    *p_M = nouveau;
}

void supprimerAssociation(MaisonDesAssociations **p_M, Association *A)
{
    MaisonDesAssociations *cour = *p_M;

    if (strcmp(cour->assoc->nom, A->nom) == 0){
        *p_M = cour->suiv;
        libererAssociation(cour->assoc);
        free(cour);
        return;
    }
    while (cour->suiv != NULL && strcmp(cour->suiv->assoc->nom, A->nom) != 0) {
        cour = cour->suiv;
    }

    if (cour->suiv != NULL){
        MaisonDesAssociations *a_suppr = cour->suiv;
        cour->suiv = a_suppr->suiv;
        libererAssociation(a_suppr->assoc);
        free(a_suppr);
    }
}

void libererAssociation(Association *A){
    Cellule *cour = A->lesMembres;
    while (cour != NULL){
        Cellule *a_suppr = cour;

        cour = cour->suivant;
        free(a_suppr->nom);
        free(a_suppr);
    }

    free(A->nom);
    free(A);
}

void libererMaison(MaisonDesAssociations *M){
    while (M != NULL){
        MaisonDesAssociations *a_suppr = M;

        M = M->suiv;
        libererAssociation(a_suppr->assoc);
        free(a_suppr);
}
}

int main(void)
{
    MaisonDesAssociations *M = creerMaisonAssoc();

    Association *sport = creerAssociation("Sport");
    Association *musique = creerAssociation("Musique");

    ajouterPersonne(sport, "Ali");
    ajouterPersonne(sport, "Sara");
    ajouterPersonne(musique, "Marie");

    ajouterAssociation(&M, sport);
    ajouterAssociation(&M, musique);

    supprimerPersonne(sport, "Ali");
    supprimerAssociation(&M, musique);

    libererMaison(M);

    return 0;
}



/*

Q2.4
typedef enum _type
{
    PHYSIQUE,
    MORALE
} TypePersonne;

typedef struct _asso Association;

typedef struct _membre
{
    Association *personnePhysiqueOuMorale;
    struct _membre *suivant;
} MembreAssoc;

struct _asso
{
    char *nom;
    char *adresse;
    TypePersonne type;
    MembreAssoc *lesMembres;
};

*/