#!/usr/bin/env python3

import sys
import pprint
import itertools

class Cell:
    def __init__(self, r, c, ingredient):
        self.r = r
        self.c = c
        self.ingredient = ingredient


class Slice:
    cells = []
    
    def __init__(self, pizza, r1, c1, r2, c2):
        self.r1 = r1
        self.c1 = c1
        self.r2 = r2
        self.c2 = c2
        for cell in pizza.cells:
            if (cell.r >= r1 and cell.c >= c1) and (cell.r <= r2 and cell.c <= c2):
                self.cells.append(cell)
    
    def is_valid(self, pizza):
        num_tomatoes = len(list(filter(lambda cell: cell.ingredient == 'T', self.cells)))
        num_mushrooms = len(list(filter(lambda cell: cell.ingredient == 'M', self.cells)))
        if num_tomatoes >= pizza.min_ingredient_num and num_mushrooms >= pizza.min_ingredient_num and len(self.cells) <= pizza.max_cell:
                return True
            
        return False
        
    def print(self):
        return '{} {} {} {}'.format(self.r1, self.c1, self.r2, self.c2)

class Pizza:
    cells = []
    slices = []

    def __init__(self):
        pass

    def read(self, filename):
        with open(filename, 'r') as f:
            pizza_info = f.readline()
            self.numrows, self.numcols, self.min_ingredient_num, self.max_cell = map(int, pizza_info.split())

            for row, line in enumerate(f.readlines()):
                for col, ingredient in enumerate(line.strip()):
                    self.cells.append(Cell(row, int(col), ingredient))

            # for r, c, line in itertools.product(range(self.numrows),
            #         range(self.numcols), f.readlines()):
            #     for ingredient in line:
            #         self.cells.append(Cell(r, c, ingredient))

    def slice(self):
        if len(self.cells) is 0:
            return self.cells
        elif len(list(filter(lambda cell: cell.ingredient == 'T', self.cells))) == 12:
            return 1
        else:
            return 2

    def print(self):
        print(len(self.slices))
        for slice in self.slices:
            print(slice.print())

if __name__ == '__main__':
    input_file = sys.argv[1]
    pizza = Pizza()
    pizza.read(input_file)
    pizza.print()
    print(pizza.slice())
