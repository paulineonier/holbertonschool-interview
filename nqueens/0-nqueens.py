#!/usr/bin/python3
"""
N Queens puzzle.
"""

import sys


def is_safe(queens, row, col):
    """
    Check if a queen can be placed at (row, col).

    Args:
        queens: Current list of placed queens.
        row: Row where the new queen should be placed.
        col: Column where the new queen should be placed.

    Returns:
        True if the position is safe, otherwise False.
    """
    for previous_row, previous_col in queens:
        if previous_col == col:
            return False

        if abs(previous_row - row) == abs(previous_col - col):
            return False

    return True


def solve(queens, row, n):
    """
    Find and print all solutions using backtracking.

    Args:
        queens: Current list of placed queens.
        row: Current row.
        n: Size of the chessboard.
    """
    if row == n:
        print(queens)
        return

    for col in range(n):
        if is_safe(queens, row, col):
            queens.append([row, col])
            solve(queens, row + 1, n)
            queens.pop()


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

if not sys.argv[1].isdigit():
    print("N must be a number")
    sys.exit(1)

n = int(sys.argv[1])

if n < 4:
    print("N must be at least 4")
    sys.exit(1)

solve([], 0, n)
