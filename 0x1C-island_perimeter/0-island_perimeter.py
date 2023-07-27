def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
        grid (list of list of int): A rectangular grid where 0 represents water and 1 represents land.

    Returns:
        int: The perimeter of the island.

    Constraints:
        - Cells are connected horizontally/vertically (not diagonally).
        - The grid is completely surrounded by water.
        - There is only one island (or nothing).
        - The island doesn’t have “lakes” (water inside that isn’t connected to the water surrounding the island).
    """
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
