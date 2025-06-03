#!/usr/bin/python3
"""
Module 0-lockboxes

This module provides a function to determine if all locked boxes
in a sequence can be opened, starting from box 0.

Each box may contain keys to other boxes. The first box is always open.
The goal is to check whether it's possible to access all boxes
using the keys contained within the boxes.
"""


def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.

    Args:
        boxes (list of lists): A list where each element represents a box,
        and each box contains a list of keys (integers) to other boxes.

    Returns:
        bool: True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)
    opened = set([0])         # Start with box 0 opened
    keys = boxes[0].copy()    # Start with keys from box 0

    while keys:
        key = keys.pop()
        if key < n and key not in opened:
            opened.add(key)
            keys.extend(boxes[key])  # Add new keys from the newly opened box

    return len(opened) == n
