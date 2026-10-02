#!/usr/bin/python3
"""
UTF-8 validation.
"""


def validUTF8(data):
    """
    Determine whether data represents a valid UTF-8 encoding.

    Args:
        data: List of integers representing bytes.

    Returns:
        True if data is valid UTF-8, otherwise False.
    """
    remaining = 0

    for value in data:
        byte = value & 0xFF

        if remaining == 0:
            if (byte & 0x80) == 0:
                continue
            elif (byte & 0xE0) == 0xC0:
                remaining = 1
            elif (byte & 0xF0) == 0xE0:
                remaining = 2
            elif (byte & 0xF8) == 0xF0:
                remaining = 3
            else:
                return False
        else:
            if (byte & 0xC0) != 0x80:
                return False

            remaining -= 1

    return remaining == 0
