#!/usr/bin/python3
"""
 method that calculates the fewest number of operations 
 needed to result in exactly n H characters in the file.
 
"""


def minOperations(n):
    """
    a method that determines the least amount of
    operation to get the desired outcome.
    """
    if (not isinstance(n, int)):
        return 0
    count = 0
    for i in range(2, n):
        while (n % i == 0):
            count += i
            n = n / i
    return count
