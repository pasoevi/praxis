import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = [int(i) for i in input().split()]
n = int(input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in input().split()]

top = 0
bottom = h - 1

left = 0
right = w - 1


# game loop
while True:
    bomb_dir = input()  # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)

    # Write an action using print
    # To debug: print("Debug messages...", file=sys.stderr)


    # the location of the next window Batman should jump to.
    if "U" in bomb_dir:
        bottom = y0 - 1
    elif "D" in bomb_dir:
        top = y0 + 1
        
    if "L" in bomb_dir:
        right = x0 - 1
    elif "R" in bomb_dir:
        left = x0 + 1
    
    x0 = left + (right - left) // 2;
    y0 = top + (bottom - top) // 2;
    

    print(f'{x0} {y0}')
