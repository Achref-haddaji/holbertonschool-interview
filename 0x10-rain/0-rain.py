#!/usr/bin/python3
"""function"""


def rain(walls):
    """function"""
    n = len(walls)
    if n == 0:
        return 0

# Calculate the maximum height of walls to the left of each wall.
    left_max = [0] * n
    right_max = [0] * n

    left_max[0] = walls[0]
    for i in range(1, n):
        left_max[i] = max(left_max[i-1], walls[i])

# Calculate the maximum height of walls to the right of each wall.
    right_max[n-1] = walls[n-1]
    for i in range(n-2, -1, -1):
        right_max[i] = max(right_max[i+1], walls[i])

# Calculate the amount of water that can be trapped between the walls.
    water = 0
    for i in range(n):
        water += min(left_max[i], right_max[i]) - walls[i]

# If the amount of water is negative, return 0.
    return water if water >= 0 else 0
