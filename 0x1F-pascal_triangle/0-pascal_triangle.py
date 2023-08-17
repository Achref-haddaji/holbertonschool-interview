#!/usr/bin/python3
"""
passcal triangle
"""


def pascal_triangle(n):
    """
passcal triangle
"""
    tringle = []
    array = []
    if (n <= 0):
        return tringle

    for line in range(0, n):
        array = []
        for i in range(0, line + 1):
            array.append(binomialCoeff(line, i))
        tringle.append(array)
    return tringle


def binomialCoeff(line, num):
    """
binomial Coeffion"""
    res = 1
    if (num > line - num):
        num = line - num
    for i in range(0, num):
        res = res * (line - i)
        res = res // (i + 1)
    return res
