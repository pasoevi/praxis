import re
import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

width, height = [int(i) for i in input().split()]
board = []
initial_position = []
pikaptcha = ['_', [-1, -1]]
for row in range(height):
    line = input()
    p = re.search("[\^>v<]", line)
    if p:
        initial_x = p.start()
        initial_y = row
        pikaptcha[0] = p.group()
        pikaptcha[1] = [initial_x, initial_y]
        initial_position[0] = initial_x;
        initial_position[1] = initial_y;
   
    board.append(list(line))

print(pikaptcha, file=sys.stderr)
side = input()

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