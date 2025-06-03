#!/usr/bin/python3

def canUnlockAll(boxes):
    """
    Determines if all the boxes can be opened.
    Args:
        boxes (list of lists): Each list contains keys to other boxes.
    Returns:
        True if all boxes can be opened, False otherwise.
    """
    n = len(boxes)
    opened = set([0])
    keys = boxes[0].copy()

    while keys:
        key = keys.pop()
        if key < n and key not in opened:
            opened.add(key)
            keys.extend(boxes[key])

    return len(opened) == n