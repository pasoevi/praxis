import sys
import math
from pprint import pprint

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

w, h = [int(i) for i in input().split()]
players = []
game_grid = []
lane_num = (w + 2) / 3
destinations = []

for i in range(h):
    line = input()
    if i == 0:
        players = [[x, line.find(x)] for x in line.split()]
    elif i == h -1:
        destinations = line #.split()
    else:
        game_grid.append(line)

for row in range(len(game_grid)):
    for player in players:
        if player[1] > 0 and game_grid[row][player[1]-1] == "-":
            player[1] -= 3
        elif player[1] < w - 1 and game_grid[row][player[1]+1] == "-":
            player[1] += 3

for player in players:
    print(f"{player[0]}{destinations[player[1]]}")
