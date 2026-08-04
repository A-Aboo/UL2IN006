#include "formation.h"

int nb_heures_total(Formation *F)
{
    if (F->liste == NULL)
        return F->nbheures;

    int total = 0;
    Cellule *cour = F->liste;
    while (cour != NULL){
        total += nb_heures_total(cour->f);
        cour = cour->suiv;
    }
    return total;
}

void afficher_avec_decalage(Formation *F, int decal)
{
    for (int i  =0; i <decal; i++)
        printf(" ");

    if (F->liste== NULL){
        printf("Cours %s (%d heures)\n", F->nom, F->nbheures);
    }else{
        printf("Formation %s (%d heures)\n",
            F->nom,nb_heures_total(F));

        Cellule *cour= F->liste;

        while (cour !=NULL)
        {
            afficher_avec_decalage(cour->f, decal+2);
            cour= cour->suiv;
        }
    }
}

void afficher_formation(Formation *F)
{
    afficher_avec_decalage(F,0);
}

void afficher_catalogue(Catalogue *C)
{
    printf("______ Catalogue ______\n");

    for (int i =0;i < C->nb_formations; i++){
        afficher_formation(C->T[i]);
        printf("\n");
    }
}

int contient(Formation *F, Formation *cherche)
{
    Cellule *cour= F->liste;

    while (cour !=NULL){
        if ( contient( cour->f, cherche))
            return 1;
        cour= cour->suiv;}
    return 0;
}

void ajouter_formation(Formation *destination,Formation *ajout)
{
    if (contient(ajout , destination) ) {
        printf("Ajout impossible : cycle\n") ;
        return;
     }

    Cellule *nouveau = malloc(sizeof(Cellule));

    if (nouveau  == NULL)
        return;
    nouveau->f =ajout;
    nouveau->suiv = destination->liste;
    destination->liste = nouveau;
}

int main(void)
{
    Formation C1 = {"C1", 12, NULL};
    Formation C2 = {"C2", 8, NULL};
    Formation C3 = {"C3", 10, NULL};

    Formation F1 = {"F1", 0, NULL};
    Formation F2 = {"F2", 0, NULL};
    Formation F3 = {"F3", 0, NULL};

    ajouter_formation(&F3, &C3);

    ajouter_formation(&F2, &F3);
    ajouter_formation(&F2, &C2);

    ajouter_formation(&F1, &F2);
    ajouter_formation(&F1, &C1);

    Formation *tab[5] = {&F1, &F2, &F3, NULL, NULL};

    Catalogue C = {5, 3, tab};

    afficher_catalogue(&C);

    printf("Duree de F1 : %d heures\n", nb_heures_total(&F1));

    return 0;
}


/*

3. Dessin du catalogue

Catalogue
M = 5
nb_formations = 3

T[0] ───> F1
T[1] ───> F2
T[2] ───> F3
T[3] ───> NULL
T[4] ───> NULL

F1
│
├── C1 : 12 heures
│
└── F2
    │
    ├── C2 : 8 heures
    │
    └── F3
        │
        └── C3 : 10 heures

7. Ajouter F1 dans F2 ou F3

F1 
    F2 
        F1
            F2 
                F1 ...


8.
Vérifier si une formation est inclue dans une autre avant de permettre l'ajout.
*/