# 2IN006 TD8

## Exercice 1

**1.1**

G1 : oriente, 6 sommets, 5 arcs.

G2 : non oriente, 6 sommets, 5 aretes.

G3 : oriente, 6 sommets, 9 arcs.

G4 : non oriente, 6 sommets, 9 aretes.

G1 et G2 sont des arbres (pas de cycle), G3 et G4 contiennent le cycle 3-4-5.

**1.2** `ajoute_lien` insere en tete, donc les listes sortent dans l'ordre inverse des insertions.

G1 :

```
0 : 4 1
1 : 5 3 2
2 :
3 :
4 :
5 :
```

G2 :

```
0 : 4 1
1 : 5 3 2 0
2 : 1
3 : 1
4 : 0
5 : 1
```

G3 :

```
0 : 4 1
1 : 5 3 2
2 : 3
3 : 4
4 : 5
5 : 3
```

G4 :

```
0 : 4 1
1 : 5 3 2 0
2 : 3 1
3 : 2 5 4 1
4 : 5 3 0
5 : 3 4 1
```

**1.3** Sur G1 : `0 4 1 5 3 2`.

Sur G2 : boucle infinie (`0 4 0 4 ...`), car chaque arete est stockee dans les deux sens, donc on revient toujours sur le pere.

**1.4** On passe le pere en parametre et on ne le reparcourt pas (`aff_parcours_2`). Sur G2 on obtient alors `0 4 1 5 3 2`.

**1.5** Sur G4 comme sur G3, ca boucle encore : ignorer le pere ne suffit pas quand il y a un vrai cycle (3-4-5), on tourne indefiniment dedans.

**1.6** Il faut un tableau `visit` : un sommet deja visite n'est pas reparcouru (`aff_parcours_3`). Sur G4 depuis 0 : `0 4 5 3 2 1`.

**1.7 a 1.10** Voir le code : statuts 0/1/2, on a un circuit des qu'on trouve un arc (k,l) avec `visit[l] == 1`. Le tableau `pred` remonte du sommet k jusqu'a l, donc a l'envers : on stocke dans un tableau et on l'affiche en sens inverse. Sur G3 : `4 -> 5 -> 3 -> 4`.

**1.11** Sur G2 et G4 la fonction trouve toujours un circuit, meme sur G2 qui n'en a pas : l'arete {i,j} donne les deux arcs (i,j) et (j,i). On corrige en ignorant le pere (`cycle_non_oriente`) : G2 -> 0, G4 -> 1.

## Exercice 2

**2.2** On fait un parcours (largeur ou profondeur) depuis r en suivant les successeurs ; tout sommet atteint est accessible depuis r.

Sur la figure, depuis 1 : 1, 2, 0, 3, 5, 6, 7 (tout sauf 4).

**2.3** `liste_ascendants` est exactement la meme fonction, mais on parcourt la liste `L_prec` (predecesseurs) au lieu de `L_succ` : on remonte les arcs au lieu de les descendre.

**2.4** j est dans la meme CFC que i s'il est a la fois descendant et ascendant de i. On prend les sommets dans l'ordre croissant, donc le premier sommet non encore classe est bien le plus petit indice de sa composante.

Resultat sur la figure : CFC0 = {0,1,2}, CFC3 = {3,5,6,7}, CFC4 = {4}.
