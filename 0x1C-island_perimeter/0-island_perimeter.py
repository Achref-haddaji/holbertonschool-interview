#!/usr/bin/python3

""" Function to find perimiter of an island """


def island_perimeter(grid):
    """ Function to find perimiter of an island """
    perimeter = 0
    land_count = 0
    neighbor_count = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                land_count += 1
                if i != (len(grid) - 1) and grid[i + 1][j] == 1:
                    neighbor_count += 1
                if j != (len(grid[i]) - 1) and grid[i][j + 1] == 1:
                    neighbor_count += 1
    perimeter = (land_count * 4) - (neighbor_count * 2)
    return perimeter
