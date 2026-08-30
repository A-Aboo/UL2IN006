# 2IN006 TD10

## Exercice 1

**1.1** Un simple parcours de graphe : on met a jour un tableau T ou T[i] contient le point de regeneration qui a permis d'atteindre le sommet i.

T definit une partition des sommets, T[i] etant le representant d'une classe (donc d'une composante connexe). Voir `composantes_connexes`.

**1.2** Si T[i] == T[j], il n'y a rien a faire : i et j sont deja dans la meme composante.

Sinon il faut fusionner les deux classes en parcourant tout le tableau : tous les k tels que T[k] == T[j] deviennent T[k] = T[i].

Complexite : O(n).

**1.3** Voir le dessin : union par rang seule, puis union par rang avec compression de chemin (rang de a = 4 dans les deux cas). La compression de chemin raccourcit les branches en rebranchant directement les noeuds traverses sur la racine.

**1.4** On part de la partition ou chaque sommet est son propre representant, puis pour chaque arete {i,j} du graphe on fait `union(i,j)`.

Validite : x et y sont relies par un chemin dans le graphe si et seulement si x et y sont dans le meme arbre de la foret.

(=>) Le chemin de x a y est une suite d'aretes, et chaque arete a donne lieu a un `union`, donc de proche en proche x et y finissent dans le meme arbre.

(<=) Si x et y etaient dans deux composantes connexes differentes X et Y, aucune arete ne relierait X a Y, donc aucun `union(i,j)` avec i dans X et j dans Y n'aurait ete fait, et x et y ne pourraient pas etre dans le meme arbre : contradiction.

**1.5** Il suffit d'appeler `union` sur les deux sommets de la nouvelle arete. Avec l'union par rang et la compression de chemin, le cout amorti de cette operation est constant.

## Exercice 2

**2.1** Soient A et B deux tas de tailles nA et nB. On cree un tas vide R, on y copie le plus grand des deux tas (O(max{nA,nB})), puis on insere un a un les elements du plus petit (O(min{nA,nB} x log(nA+nB))).

Total : O(max{nA,nB} + min{nA,nB} x log(nA+nB)).

**2.2.1** B4 = deux B3, la racine de l'un devenant le fils le plus a gauche de l'autre (16 noeuds, hauteur 4).

**2.2.2** Pour passer de Bi a Bi+1 on ajoute exactement un fils a la racine, et la racine de B0 a 0 fils : par recurrence la racine de Bi a i fils.

**2.2.3** h(Bi) = i : B0 a une hauteur de 0, et Bi est un Bi-1 auquel on accroche un Bi-1, donc h(Bi) = 1 + h(Bi-1) = 1 + (i-1) = i.

n(Bi) = 2^i : B0 a 1 = 2^0 noeud, et Bi est compose de deux Bi-1 sans ajout de noeud, donc n(Bi) = 2 x 2^(i-1) = 2^i.

**2.2.5** Voir `unionAB` : la structure est efficace car les champs `fils_gauche` et `frere_a_droite` permettent de faire l'union de deux arbres binomiaux en O(1).

**Partie B** Un tas binomial de n elements a au plus [log2(n) + 1] arbres, et avec 10 arbres on stocke jusqu'a 2^10 - 1 elements.

La decomposition suit l'ecriture binaire de n : 8 = 2^3 donne un seul B3, 10 = 2^3 + 2^1 donne un B3 et un B1, 7 = 2^2 + 2^1 + 2^0 donne un B2, un B1 et un B0.

Le minimum est une racine, donc `min` parcourt les 10 racines : O(log(n)). La fusion se fait comme une addition binaire (retenue), et l'insertion est l'union du tas avec un tas d'un seul element.
