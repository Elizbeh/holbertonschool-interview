#!/usr/bin/python3
"""
Minimum Operations implementation
"""


def minOperations(n):
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

# Example usage:
n = 19170307
result = minOperations(n)
print(f"Number of operations to get {n} 'H' characters: {result}")

