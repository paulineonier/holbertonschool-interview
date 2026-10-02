# Slide Line

## Description

Le but de cet exercice est de reproduire une partie du fonctionnement du jeu **2048**, mais sur une seule ligne.

On reçoit un tableau d'entiers :

```
2 2 0 4 4 0 8
```

On doit pouvoir le faire glisser :

-   vers la gauche
    
-   vers la droite
    

Pendant le déplacement :

1.  Les `0` sont ignorés.
    
2.  Les nombres se rapprochent de la direction choisie.
    
3.  Deux nombres identiques qui se suivent fusionnent.
    
4.  Lorsqu'ils fusionnent, ils sont additionnés.
    
5.  Une paire ne peut fusionner qu'une seule fois pendant un déplacement.
    

### Exemple

```
2 2 0 0
```

Vers la gauche :

```
4 0 0 0
```

Car :

```
2 + 2 = 4
```

Autre exemple :

```
2 2 2 2
```

Vers la gauche :

```
4 4 0 0
```

On ne fait pas :

```
8 0 0 0
```

car chaque paire ne peut fusionner qu'une seule fois.

---

## Prototype

```
int slide_line(int *line, size_t size, int direction);
```

### Paramètres

-   `line` : tableau d'entiers à modifier
    
-   `size` : nombre d'éléments du tableau
    
-   `direction` : direction du déplacement
    

Les directions sont définies dans `slide_line.h` :

```
#define SLIDE_LEFT  1
#define SLIDE_RIGHT 2
```

---

## Valeur de retour

La fonction retourne :

```
1
```

si la direction est valide et que l'opération est effectuée.

Elle retourne :

```
0
```

si la direction n'est pas valide.

---

## Contrainte

Il est interdit d'utiliser :

```
malloc
calloc
realloc
```

ou toute autre allocation dynamique.

Le tableau fourni doit être modifié directement.

---

## Principe de résolution

Pour chaque direction, on fait deux grandes étapes :

### Étape 1 — Faire glisser les nombres

On enlève les `0` du milieu en rapprochant les nombres.

Exemple :

```
2 0 0 4 0 2
```

vers la gauche devient :

```
2 4 2 0 0 0
```

### Étape 2 — Fusionner les nombres identiques

```
2 2 4 4
```

devient :

```
4 8 0 0
```

Les nombres sont ensuite complétés avec des `0`.

---

## Complexité

La solution fonctionne directement dans le tableau et n'utilise pas de mémoire dynamique.

Le déplacement et les fusions peuvent nécessiter plusieurs parcours du tableau.