#!/usr/bin/python3

"""Solve the queens"""

import sys


def queen_pos(board, pos):
    """Check if it's safe to place a queen at a given position"""

    for queen in board:
        if queen[1] == pos[1]:
            return False
        if (queen[0] + queen[1]) == (pos[0] + pos[1]):
            return False
        if (queen[0] - queen[1]) == (pos[0] - pos[1]):
            return False
    return True


def place_queens(x, n, board):
    """Solve the queens problem using recursive backtracking"""

    if x == n:
        print(board)
    else:
        for y in range(n):
            pos = [x, y]
            if queen_pos(board, pos):
                board.append(pos)
                place_queens(x + 1, n, board)
                board.remove(pos)


if __name__ == '__main__':
    """Main function to run the program"""

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not sys.argv[1].isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(sys.argv[1])

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = []
    place_queens(0, n, board)
