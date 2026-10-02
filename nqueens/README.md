x# N Queens

## Objectif

Le problème des **N Queens** consiste à placer `N` reines sur un échiquier de taille `N × N` sans qu'aucune reine ne puisse attaquer une autre.

Le programme doit trouver et afficher **toutes les solutions possibles**.

### Utilisation

```
./0-nqueens.py N
```

Par exemple :

```
./0-nqueens.py 4
```

---

## Règles

Deux reines ne doivent jamais être sur :

-   la même ligne ;
    
-   la même colonne ;
    
-   la même diagonale.
    

Une reine peut se déplacer horizontalement, verticalement et diagonalement.

---

## Contraintes

Le programme doit respecter les règles suivantes :

-   Si le nombre d'arguments est incorrect, afficher :
    

```
Usage: nqueens N
```

et quitter avec le code `1`.

-   Si `N` n'est pas un entier, afficher :
    

```
N must be a number
```

et quitter avec le code `1`.

-   Si `N` est inférieur à `4`, afficher :
    

```
N must be at least 4
```

et quitter avec le code `1`.

-   Le programme doit afficher toutes les solutions.
    
-   Une solution doit être affichée par ligne.
    
-   L'ordre des solutions n'est pas imposé.
    
-   Seul le module `sys` peut être importé.
    

---

## Représentation d'une solution

Une solution est représentée sous la forme :

```
[[row, column], [row, column], ...]
```

Par exemple :

```
[[0, 1], [1, 3], [2, 0], [3, 2]]
```

signifie :

```
Ligne 0 → colonne 1
Ligne 1 → colonne 3
Ligne 2 → colonne 0
Ligne 3 → colonne 2
```

On place donc une seule reine par ligne.

---

## Principe du backtracking

Le programme construit une solution progressivement.

Pour chaque ligne :

1.  essayer une colonne ;
    
2.  vérifier si la position est valide ;
    
3.  placer la reine ;
    
4.  passer à la ligne suivante ;
    
5.  si aucune position ne fonctionne, revenir en arrière ;
    
6.  déplacer la reine précédente et essayer une autre position.
    

C'est ce retour en arrière qui s'appelle le **backtracking**.

Schématiquement :

```
Choisir
   ↓
Vérifier
   ↓
Placer
   ↓
Continuer
   ↓
Impossible ?
   ↓
Revenir en arrière
   ↓
Essayer une autre possibilité
```

---

## Vérification des attaques

Pour deux reines placées aux positions :

```
(row1, col1)
(row2, col2)
```

elles sont sur la même colonne si :

```
col1 == col2
```

Elles sont sur la même diagonale si :

```
abs(row1 - row2) == abs(col1 - col2)
```

Si aucune de ces conditions n'est vraie, les deux reines ne s'attaquent pas.

---

## Complexité

Le problème des N Queens est un problème de recherche combinatoire.

Le nombre de possibilités augmente très rapidement avec `N`.

Le backtracking permet de supprimer très tôt les configurations impossibles au lieu de tester toutes les configurations possibles jusqu'au bout.