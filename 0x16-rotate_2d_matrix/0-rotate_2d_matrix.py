#!/usr/bin/python3
"""
Task 0x16 - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Rotation """
    n = len(matrix)
    # Transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    # Reverse each row
    for i in range(n):
        matrix[i] = matrix[i][::-1]
