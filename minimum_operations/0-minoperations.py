#!/usr/bin/python3
"""
Minimum operation
"""


def minOperations(n):
    if n == 1:
        return 0
    
    operations = 0
    h = 1
    while h < n:
        if n % h == 0:
            operations += 2
            h *= 2
        else:
            operations += 1
            h += h - n % h

    return operations
