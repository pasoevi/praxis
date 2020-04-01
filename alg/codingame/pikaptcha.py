import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

width, height = [int(i) for i in input().split()]
board = []
for i in range(height):
    board.append(list(input()))
for row in range(height):
    for col in range(width):
        num_passages = 0
        if board[row][col] == "0":
            if col > 0 and board[row][col-1] != "#":
                num_passages += 1
            if col < width - 1 and board[row][col+1] != "#":
                num_passages += 1
            if row > 0 and board[row-1][col] != "#":
                num_passages += 1
            if row < height - 1 and board[row+1][col] != "#":
                num_passages += 1
            board[row][col] = num_passages
    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)

    print(row)