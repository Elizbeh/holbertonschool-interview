#!/usr/bin/python3
"""
Minimum operation
"""


def minOperations(n):
    """
    Calculates the minimum number of operations
    needed to obtain 'n' 'H' characters using the
    "Copy All" and "Paste" operations.

    Args:
    n (int): The desired number of 'H' characters.

    Returns:
    int: The minimum number of operations required.

    Note:
    If 'n' is impossible to achieve, it returns 0.
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            n //= divisor
            operations += divisor

        divisor += 1

    return operations
