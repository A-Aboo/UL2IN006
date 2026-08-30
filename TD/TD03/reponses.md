# UL2IN006 TD3

## Exercice 1 : empreintes digitales

**1.1** Une table de hachage cle-valeur : la cle est l'empreinte (le vecteur des six entiers), la valeur est la fiche personnelle.

**1.2** L'espace des empreintes est enorme mais le tableau est limite a 100 000 cases : la fonction de hachage doit donc ramener la cle dans [0, 99999], typiquement avec un `% 100000`, en repartissant les valeurs le plus uniformement possible.

**1.3** `g` n'est pas bonne :

- le produit x1 * ... * x6 deborde vite la capacite d'un `int` ;
- il suffit qu'un xi vaille 0 pour que le hachage vaille 0 ;
- le produit est invariant par permutation : deux empreintes contenant les memes six nombres dans un ordre different donnent le meme hachage.

On la remplace par une somme ponderee par des coefficients differents (des nombres premiers), qui tient compte de la position :

```
h = (x1*31 + x2*37 + x3*41 + x4*43 + x5*47 + x6*53) % 100000;
```

**1.4** Avec cette nouvelle fonction :

```
[02, 04, 10, 01, 00, 17] -> 62 + 148 + 410 + 43 + 0   + 901 = 1564
[02, 10, 00, 02, 09, 05] -> 62 + 370 + 0   + 86 + 423 + 265 = 1206
[00, 01, 17, 04, 02, 10] -> 0  + 37  + 697 + 172 + 94 + 530 = 1530
```

La troisieme cle est une permutation de la premiere : avec l'ancienne fonction elles se seraient hachees pareil (0 dans les deux cas), la ponderation les separe bien.

En revanche les trois valeurs restent minuscules devant 100000 : comme les xi valent au plus 99, la somme ponderee ne depasse jamais environ 25000, et tout se tasse au debut du tableau. Pour utiliser toute la table on prend plutot un schema de Horner, qui traite les six entiers comme les chiffres d'un grand nombre en base 100 :

```
h = 0;
pour chaque xi : h = (h * 100 + xi) % 100003;
```

(un modulo premier proche de 100000 repartit mieux qu'une puissance de 10).

## Exercice 2 : comparaison de differents types de tables

**2.1** g(k) = k mod 16, c'est simplement le dernier chiffre hexadecimal de la cle :

| mot | cle | g(k) |
|---|---|---|
| le | FF2E | 14 |
| cours | 178DD38 | 8 |
| appele | 75EA33 | 3 |
| structures | 35CE5 | 5 |
| de | 9AA8BF1 | 1 |
| donnees | 2738 | 8 |
| est | A4C74 | 4 |
| absolument | 1CA4C74 | 4 |
| genial | 14D26 | 6 |
| j'adore | 5A38 | 8 |
| faire | 1BAE5 | 5 |
| ses | 65B4EE5 | 5 |
| TD/TME | 8C74 | 4 |

**2.2**

**1. Chainage**

```
C00 :
C01 : de
C02 :
C03 : appele
C04 : est -> absolument -> TD/TME
C05 : structures -> faire -> ses
C06 : genial
C07 :
C08 : cours -> donnees -> j'adore
C09 :
...
C14 : le
C15 :
```

**2. Adressage ouvert, probing lineaire** h(k,i) = g(k) + i

```
C00 :
C01 : de           C1                                    1 sondage
C02 :
C03 : appele       C3                                    1
C04 : est          C4                                    1
C05 : structures   C5                                    1
C06 : absolument   C4 C5 C6                              3
C07 : genial       C6 C7                                 2
C08 : cours        C8                                    1
C09 : donnees      C8 C9                                 2
C10 : j'adore      C8 C9 C10                             3
C11 : faire        C5 C6 C7 C8 C9 C10 C11                7
C12 : ses          C5 ... C12                            8
C13 : TD/TME       C4 ... C13                           10
C14 : le           C14                                   1
C15 :
```

Moyenne : 41 / 13 = 3,15 sondages.

**3. Adressage ouvert, probing quadratique** h(k,i) = g(k) + i/2 + i^2/2, c'est-a-dire des decalages 0, 1, 3, 6, 10, 15, 21, 28 (les nombres triangulaires)

```
C00 : TD/TME       C4 C5 C7 C10 C14 C3 C9 C0             8 sondages
C01 : de           C1                                    1
C02 :
C03 : appele       C3                                    1
C04 : est          C4                                    1
C05 : structures   C5                                    1
C06 : genial       C6                                    1
C07 : absolument   C4 C5 C7                              3
C08 : cours        C8                                    1
C09 : donnees      C8 C9                                 2
C10 : ses          C5 C6 C8 C11 C15 C4 C10               7
C11 : j'adore      C8 C9 C11                             3
C12 :
C13 :
C14 : le           C14                                   1
C15 : faire        C5 C6 C8 C11 C15                      5
```

Moyenne : 35 / 13 = 2,69 sondages.

Le probing quadratique est donc meilleur : le lineaire cree de longs paquets (clustering primaire) que toutes les cles suivantes doivent traverser, alors que les sauts croissants du quadratique dispersent les collisions. Le chainage reste le plus simple et ne souffre pas du remplissage de la table.

## Exercice 3 : fonctions de hachage

**3.1** Avec g(x) = f(x) mod 10 :

| mot | x | f1=x | g1 | f2=10x | g2 | f3=2x | g3 | f4 | g4 |
|---|---|---|---|---|---|---|---|---|---|
| le | 123 | 123 | 3 | 1230 | 0 | 246 | 6 | 83 | 3 |
| cours | 22 | 22 | 2 | 220 | 0 | 44 | 4 | 18 | 8 |
| appele | 88 | 88 | 8 | 880 | 0 | 176 | 6 | 72 | 2 |
| structures | 43 | 43 | 3 | 430 | 0 | 86 | 6 | 35 | 5 |
| de | 4 | 4 | 4 | 40 | 0 | 8 | 8 | 4 | 4 |
| donnees | 28 | 28 | 8 | 280 | 0 | 56 | 6 | 24 | 4 |
| est | 73 | 73 | 3 | 730 | 0 | 146 | 6 | 59 | 9 |
| absolument | 7 | 7 | 7 | 70 | 0 | 14 | 4 | 7 | 7 |
| genial | 13 | 13 | 3 | 130 | 0 | 26 | 6 | 11 | 1 |

(f4(x) = 8 * f4(x/10) + x%10 : on relit les chiffres decimaux comme s'ils etaient en base 8.)

**3.2**

- f2 = 10x : toutes les cles tombent en 0, c'est le pire cas possible.
- f3 = 2x : le hachage est toujours pair, la moitie des cases est inutilisable, et tout se concentre sur 6.
- f1 = x : correct mais on garde les collisions naturelles des cles (quatre mots sur 3).
- f4 : 3, 8, 2, 5, 4, 4, 9, 7, 1, presque une case differente par mot.

f4 est la meilleure : en changeant de base elle melange les chiffres au lieu de ne garder que le dernier.

## Exercice 4 : tables de hachage par chainage

**4.1** Un tableau de listes chainees : chaque case contient la liste des couples (cle, valeur) qui se hachent vers cette case. Voir `List` et `T_hache`, alloues par `cree_Thache`.

**4.2** Voir `inserer` : on calcule l'indice avec `hache`, puis on insere l'element en tete de la liste correspondante, ce qui se fait en O(1).

**4.3** On ajoute un champ `nb_elem` dans la structure, incremente a chaque insertion et decremente a chaque suppression : le nombre d'elements est alors connu en O(1), au lieu de devoir parcourir toutes les listes.

**4.4** Voir `supprime_elem`. Avec une liste simplement chainee il faut garder le predecesseur pour rechainer. Une liste **doublement chainee** rendrait la suppression plus simple et en O(1) une fois l'element trouve, puisqu'on aurait directement acces a son precedent.
