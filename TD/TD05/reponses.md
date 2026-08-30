# UL2IN006 TD5

## Exercice 1

**1.1** Un tas (min) est un arbre binaire complet, tasse a gauche, dans lequel la cle de chaque noeud est inferieure ou egale a celle de ses fils.

La racine contient donc toujours le minimum. Operations : inserer, supprimer le minimum, lire le minimum.

**1.2** Insertions successives de 10, 2, 5, 4, 7, 15, 1, 3 (a chaque fois on place l'element en derniere position puis on le fait remonter par des `swap(pere, fils)`) :

```
10
10 2          -> swap(1,2)  -> 2 10
2 10 5
2 10 5 4      -> swap(2,4)  -> 2 4 5 10
2 4 5 10 7
2 4 5 10 7 15
2 4 5 10 7 15 1 -> swap(3,7) -> 2 4 1 10 7 15 5 -> swap(1,3) -> 1 4 2 10 7 15 5
1 4 2 10 7 15 5 3 -> swap(4,8) -> swap(2,4) -> 1 3 2 4 7 15 5 10
```

Tas obtenu :

```
          1
      3       2
    4   7   15  5
  10
```

**1.3** Suppression du minimum : on remplace la racine par le dernier element (10), puis on le fait descendre en l'echangeant avec le plus petit de ses fils.

```
10 3 2 4 7 15 5   -> swap(1,3) -> 2 3 10 4 7 15 5
                  -> swap(3,7) -> 2 3 5 4 7 15 10
```

Tas obtenu :

```
        2
     3     5
   4   7  15  10
```

**1.4** Un tas de hauteur h contient entre 2^h et 2^(h+1) - 1 elements.

**1.5** h = partie entiere de log2(n).

**1.6** Insertion : O(h) = O(log2(n)) dans le pire des cas (l'element remonte jusqu'a la racine).

Suppression du minimum : O(h) = O(log2(n)) aussi (l'element redescend jusqu'a une feuille).

## Exercice 2

**2.1** Tas ternaire construit a partir de 3, 6, 1, 13, 17, 18, 2 : `1 2 3 13 17 18 6`

```
           1
     2     3     13
  17 18 6
```

**2.2** h = partie entiere de log3(n), avec 3^h <= n <= 3^(h+1) - 1 pour un tas complet.

L'arbre est moins haut, donc l'insertion fait moins de remontees : le cout est divise par log2(3) environ 1,58. Ca reste du O(log(n)), seule la constante s'ameliore (et en echange chaque descente coute 3 comparaisons au lieu de 2).

**2.3** En numerotant a partir de 1, les fils du noeud i sont 3i-1, 3i et 3i+1, et son pere est la partie entiere de (i+1)/3 (c'est bien (i+1)/3 et non (i-1)/3, sinon le pere du noeud 2 serait 0).

L'arbre etant complet, on stocke le tas dans un tableau ou la case i contient le noeud numero i (la case 0 n'est pas utilisee). Voir `pere`, `fils`, `inserer` et `afficherTas`.

**2.4** Voir `supprimerMin` : on retient la racine, on la remplace par la derniere feuille, puis on fait descendre cette valeur en l'echangeant avec le plus petit de ses trois fils tant qu'elle est plus grande.

**2.5** O(log3(n)), avec 3 comparaisons par niveau, donc toujours O(log(n)).
