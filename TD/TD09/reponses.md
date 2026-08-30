# UL2IN006 TD9

## Exercice 1

**1.1** Avec p = 0 : une liste chainee classique (une seule couche).

Avec p = 1 : une infinite de couches, toutes completes.

Le parametre p est un compromis entre temps de recherche et memoire consommee, en pratique p = 1/2 ou 1/4.

**1.2** Pour simuler la dichotomie on prendrait p = 1/2, en gardant le milieu de chaque sous-liste pour la couche suivante.

Probleme : a chaque insertion il faudrait reorganiser toutes les couches (supprimer des raccourcis, en rajouter).

**1.5** On parcourt la couche Ln ; des que l'element suivant est strictement plus grand que val, on descend d'une couche (idem si on arrive au bout de la liste).

Arrive en L0, on insere l'element au bon endroit, puis on tire une probabilite p pour savoir s'il monte dans la couche du dessus, et ainsi de suite, en creant de nouvelles couches si besoin.

Il faut donc sauvegarder le chemin parcouru (tableau `path`).

## Exercice 2

**2.4** On insere un noeud rouge comme dans un ABR, puis on applique des changements de couleurs et/ou des rotations suivant les 7 cas du cours (slides 15 a 20).

**2.5** Soit h la hauteur et n la taille : l'insertion est en O(h), or h est en O(log2(n)), donc l'insertion est en O(log2(n)).

Insertion, recherche et suppression sont logarithmiques. Par rapport a un AVL, l'arbre rouge-noir economise des rotations, car il ne cherche pas a etre le plus equilibre possible.
