#!/usr/bin/python3
"""island_perimeter
    """


def island_perimeter(grid):
    """_summary_

    Args:
        grid (list): list of sea of 0 that hold a island if 1

    Returns:
        int: perimeter of the island
    """
    perimeter = 0
    land = 0
    neighbor = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                land += 1
                if i != (len(grid) - 1) and grid[i + 1][j] == 1:
                    neighbor += 1
                if j != (len(grid[i]) - 1) and grid[i][j + 1] == 1:
                    neighbor += 1
    perimeter = (land * 4) - (neighbor * 2)
    return perimeter
