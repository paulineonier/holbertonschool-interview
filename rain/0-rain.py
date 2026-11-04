#!/usr/bin/python3
"""
Calculate the amount of rainwater retained between walls.
"""


def rain(walls):
    """
    Calculate how much rainwater can be trapped between walls.

    Args:
        walls (list): A list of non-negative integers
                      representing wall heights.

    Returns:
        int: The total amount of retained rainwater.
    """
    if not walls:
        return 0

    n = len(walls)

    left_max = [0] * n
    right_max = [0] * n

    left_max[0] = walls[0]

    for i in range(1, n):
        left_max[i] = max(left_max[i - 1], walls[i])

    right_max[n - 1] = walls[n - 1]

    for i in range(n - 2, -1, -1):
        right_max[i] = max(right_max[i + 1], walls[i])

    total_water = 0

    for i in range(n):
        water = min(left_max[i], right_max[i]) - walls[i]
        total_water += max(0, water)

    return total_water
