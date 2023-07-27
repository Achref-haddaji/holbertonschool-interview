#!/usr/bin/python3

""" Function  that returns the perimeter of the island described in grid """


def island_perimeter(grid):
    if not grid or not grid[0]:
        return 0

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                perimeter += 4  # Start with the maximum perimeter for each land cell.

                # Check adjacent cells and reduce the perimeter for each connected side.
                if r > 0 and grid[r - 1][c] == 1:
                    perimeter -= 2
                if c > 0 and grid[r][c - 1] == 1:
                    perimeter -= 2

    return perimeter
