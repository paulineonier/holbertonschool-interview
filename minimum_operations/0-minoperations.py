#!/usr/bin/python3
"""
Module pour calculer le nombre minimum d'opérations
pour obtenir n caractères 'H'.
"""


def minOperations(n):
    """
    Calcule le nombre minimum d'opérations (Copy All & Paste)
    nécessaires pour atteindre exactement n caractères 'H'.

    Args:
        n (int): Le nombre cible de caractères 'H'.

    Returns:
        int: Le nombre minimal d'opérations, ou 0 si n <= 1.
    """
    if n <= 1:
        return 0

    ops = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            ops += divisor
            n //= divisor
        divisor += 1

    return ops
