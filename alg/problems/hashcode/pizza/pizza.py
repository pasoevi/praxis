#!/usr/bin/env python3

import sys
import pprint
import itertools

def partition(pred, iterable):
    'Use a predicate to partition entries into false entries and true entries'
    # partition(is_odd, range(10)) --> 0 2 4 6 8   and  1 3 5 7 9
    n = 6
    combinations = [iterable[i:i + n] for i in range(0, len(iterable), n)]

    return filter(pred, combinations)

class Cell:
    def __init__(self, r, c, ingredient):
        self.r = r
        self.c = c
        self.ingredient = ingredient


class Slice:
    cells = []
    num_tomatoes = 0
    num_mushrooms = 0
    
    def __init__(self, pizza=None, r1=0, c1=0, r2=0, c2=0):
        self.r1 = r1
        self.c1 = c1
        self.r2 = r2
        self.c2 = c2
        if pizza:
            for cell in pizza.cells:
                if (cell.r >= r1 and cell.c >= c1) and (cell.r <= r2 and cell.c <= c2):
                    self.cells.append(cell)

    def from_cells(self, cells):
        self.num_tomatoes = len(list(filter(lambda cell: cell.ingredient == 'T', self.cells)))
        self.num_mushrooms = len(list(filter(lambda cell: cell.ingredient == 'M', self.cells)))
        self.cells = cells

    def is_valid(self, pizza):
        self.num_tomatoes = len(list(filter(lambda cell: cell.ingredient == 'T', self.cells)))
        self.num_mushrooms = len(list(filter(lambda cell: cell.ingredient == 'M', self.cells)))
        if self.num_tomatoes >= pizza.min_ingredient_num and self.num_mushrooms >= pizza.min_ingredient_num and len(self.cells) <= pizza.max_cell:
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

    # def slice(self):
    #     if len(self.cells) is 0:
    #         return self.cells
    #     for cell1, cell2 in 

    def slice(self):
        def is_valid(lst):
            slice = Slice()
            slice.from_cells(lst)
            
            return slice.is_valid(self)

        self.slices = list(partition(is_valid, self.cells))

    def print(self):
        print(len(self.slices))
        for slice in self.slices:
            print(slice.print())

if __name__ == '__main__':
    input_file = sys.argv[1]
    pizza = Pizza()
    pizza.read(input_file)
    
    print(pizza.slice())
    pizza.print()
