# Validation UTF-8

## Objectif

Écrire une fonction `validUTF8(data)` qui vérifie si une liste d'entiers représente une séquence valide de caractères encodés en **UTF-8**.

### Prototype

```
def validUTF8(data)
```

La fonction doit retourner :

-   `True` si les données représentent un encodage UTF-8 valide.
    
-   `False` si l'encodage est invalide.
    

---

## Contraintes

-   `data` est une liste d'entiers.
    
-   Chaque entier représente un octet (`byte`) de données.
    
-   Un caractère UTF-8 peut être composé de **1 à 4 octets**.
    
-   La liste peut contenir plusieurs caractères à la suite.
    
-   Seuls les **8 bits de poids faible** de chaque entier doivent être pris en compte.
    

Par exemple :

```
65
```

correspond à :

```
01000001
```

et représente le caractère `A`.

Un entier comme :

```
256
```

est représenté sur plus de 8 bits, mais seuls ses 8 bits de poids faible sont pris en compte.

---

## Comment fonctionne UTF-8 ?

Un caractère UTF-8 peut utiliser entre 1 et 4 octets.

### Caractère sur 1 octet

Le premier bit est `0` :

```
0xxxxxxx
```

Exemple :

```
01000001
```

Le caractère est donc valide.

---

### Caractère sur 2 octets

Le premier octet commence par :

```
110xxxxx
```

Le deuxième octet doit commencer par :

```
10xxxxxx
```

---

### Caractère sur 3 octets

Le premier octet commence par :

```
1110xxxx
```

Les deux octets suivants doivent commencer par :

```
10xxxxxx
```

---

### Caractère sur 4 octets

Le premier octet commence par :

```
11110xxx
```

Les trois octets suivants doivent commencer par :

```
10xxxxxx
```

---

## Principe de résolution

On parcourt la liste de gauche à droite.

Pour chaque octet :

1.  On regarde le premier octet.
    
2.  On détermine combien d'octets composent le caractère.
    
3.  On vérifie que les octets suivants commencent tous par `10`.
    
4.  Si un octet ne respecte pas cette règle, on retourne `False`.
    
5.  Si toute la liste est correctement parcourue, on retourne `True`.
    

Pour examiner les 8 bits de poids faible, on peut utiliser :

```
num & 0xFF
```

Pour vérifier si un octet commence par `10`, on peut utiliser :

```
(num & 0xC0) == 0x80
```

---

## Exemples

```
validUTF8([65])
```

Retourne :

```
True
```

Car `65` correspond à un caractère UTF-8 sur un octet.

```
validUTF8([229, 65, 127, 256])
```

Retourne :

```
False
```

car `229` commence un caractère UTF-8 sur plusieurs octets, mais `65` ne possède pas le format attendu pour un octet de continuation.

---

## Complexité

Si `n` est le nombre d'octets :

-   Temps : `O(n)`
    
-   Mémoire supplémentaire : `O(1)`
    

La liste est parcourue une seule fois et aucun tableau supplémentaire n'est nécessaire.