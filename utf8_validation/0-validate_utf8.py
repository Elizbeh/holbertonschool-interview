#!/usr/bin/python3
""" A method that determines if a given data set
represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    Determine if a given data set represents a valid
    UTF-8 encoding.

    :param data: A list of integers, where each integer
    represents 1 byte of data.
    :return: True if data is a valid UTF-8 encoding,
    else return False.
    """
    remaining = 0

    for num in data:
        if remaining == 0:
            if (num >> 7) & 1 == 0:
                remaining = 0  # Single-byte character
            elif (num >> 5) & 7 == 6:
                remaining = 1  # Two-byte character
            elif (num >> 4) & 15 == 14:
                remaining = 2  # Three-byte character
            elif (num >> 3) & 31 == 30:
                remaining = 3  # Four-byte character
            else:
                return False
        else:
            if (num >> 6) & 3 != 2:
                return False
            remaining -= 1

    return remaining == 0
