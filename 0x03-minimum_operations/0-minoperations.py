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
   newvalue = n
    i = 2
    rest = 0
    if (not isinstance(n, int)):
        return 0
    if n < 2:
        return 0
    while newvalue != 1:
        if newvalue % i == 0:
            newvalue = newvalue / i
            rest += i
        else:
            i = i + 1
    return rest

