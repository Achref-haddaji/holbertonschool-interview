#!/usr/bin/python3

""" Function to find the perimeter of an island """


def find_island_perimeter(grid):
    """ Function to find the perimeter of an island """
    perimeter = 0
    for x in range(len(grid)):
        for y in range(len(grid[x])):
            if grid[x][y] == 1:
                if x - 1 < 0 or grid[x - 1][y] == 0:
                    perimeter += 1
                if x + 1 >= len(grid) or grid[x + 1][y] == 0:
                    perimeter += 1
                if y - 1 < 0 or grid[x][y - 1] == 0:
                    perimeter += 1
                if y + 1 >= len(grid[x]) or grid[x][y + 1] == 0:
                    perimeter += 1
    return perimeter
