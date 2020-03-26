import sys
import math
from pprint import pprint

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.
X
n = int(input())
light = int(input())
room = []
for i in range(n):
    room.append(input().split())

room_num = [[0 for col in range(n)] for row in range(n)]

candles = []

for i in range(n):
    for j in range(n):
        if room[i][j] == "C":
            candles.append([j, i])

for candle in candles:
    candle_x, candle_y = candle
    room_num[candle_y][candle_x] = light
    fading_light = light - 1
    print(f"candle_x: {candle_x}, candle_y: {candle_y}", file=sys.stderr)
    while fading_light > 0:
        radius = light - fading_light
        top = max(0, candle_y - radius)
        left = max(0, candle_x - radius)
        bottom = min(n, candle_y + radius + 1)
        right = min(n, candle_x + radius + 1)
        for y in range(top, bottom):
            for x in range(left, right):
                if y == top or y == bottom - 1 or x == left or x == right - 1:
                    room_num[y][x] = max(room_num[y][x], fading_light)
        fading_light -= 1
num_black = 0
for y in range(n):
    for x in range(n):
        if room_num[y][x] == 0:
            num_black += 1

print(num_black)

"""
5
3
C X X X C
X X X X X
X X X X X
X X X X X
C X X X C
"""