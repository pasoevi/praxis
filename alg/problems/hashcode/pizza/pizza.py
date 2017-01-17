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


# class Cell:
#     def __init__(self, r, c, ingredient):
#         self.r = r
#         self.c = c
#         self.ingredient = ingredient


# class Slice:
#     cells = []
#     num_tomatoes = 0
#     num_mushrooms = 0
#
#     def __init__(self, pizza=None, r1=0, c1=0, r2=0, c2=0):
#         self.r1 = r1
#         self.c1 = c1
#         self.r2 = r2
#         self.c2 = c2
#         if pizza:
#             for cell in pizza.cells:
#                 if (cell.r >= r1 and cell.c >= c1) and (cell.r <= r2 and cell.c <= c2):
#                     self.cells.append(cell)
#
#     def from_cells(self, cells):
#         self.num_tomatoes = len(list(filter(lambda cell: cell.ingredient == 'T', self.cells)))
#         self.num_mushrooms = len(list(filter(lambda cell: cell.ingredient == 'M', self.cells)))
#         self.cells = cells
#
# def is_valid(slice, L, H):
#     num_tomatoes = len(list(filter(lambda cell: cell.ingredient == 'T', self.cells)))
#     num_mushrooms = len(list(filter(lambda cell: cell.ingredient == 'M', self.cells)))
#     if num_tomatoes >= L and num_mushrooms >= L and len(
#             self.cells) <= pizza.max_cell:
#         return True
#
#     return False

def count_cells(slice):
    return (abs(slice.x[0] - slice.y[0]) + 1) * (abs(slice.x[1] - slice.y[1]) + 1)


#
#     def print(self):
#         return '{} {} {} {}'.format(self.r1, self.c1, self.r2, self.c2)
def is_intersected(slice1, slice2):
    if slice1.y[0] < slice2.x[0] or slice2.y[0] < slice1.x[0] or slice1.y[1] < slice2.x[1] or slice2.y[1] < slice1.x[1]:
        return False
    else:
        return True


class Slice:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Pizza:
    matrix = []
    slices = []

    def __init__(self):
        pass

    def count_tomatoes(self, slice):
        count = 0
        for i in range(slice.x[0], slice.y[0] + 1):
            for j in range(slice.x[1], slice.y[1] + 1):
                if self.matrix[i][j] == 'T':
                    count += 1
        return count

    def count_mushrooms(self, slice):

        count = 0
        for i in range(slice.x[0], slice.y[0] + 1):
            for j in range(slice.x[1], slice.y[1] + 1):
                if self.matrix[i][j] == 'M':
                    count += 1
        return count

    def read(self, filename):
        with open(filename, 'r') as f:
            pizza_info = f.readline()
            self.numrows, self.numcols, self.min_ingredient_num, self.max_cell = map(int, pizza_info.split())

            for row, line in enumerate(f.readlines()):
                row = []
                for col, ingredient in enumerate(line.strip()):
                    # self.cells.append(Cell(row, int(col), ingredient))
                    row.append(ingredient)
                self.matrix.append(row)

    def is_valid(self, slice):
        num_tomatoes = self.count_tomatoes(slice)
        # print("num_tomatoes", num_tomatoes)
        num_mushrooms = self.count_mushrooms(slice)
        # print("num_mushrooms", num_mushrooms)
        count = count_cells(slice)
        if count > self.max_cell:
            print("rr")
        if num_tomatoes < self.min_ingredient_num or num_mushrooms < self.min_ingredient_num \
                or count > self.max_cell:
            return False
        else:
            return True

    def slice(self, slice):
        if self.is_valid(slice):
            for s in self.slices:
                if is_intersected(slice, s):
                    raise Exception('slices intercepted')
            self.slices.append(slice)
        else:
            raise Exception("invalid slice")

        def print_pizza(self):
            for row in self.matrix:
                string_row = ''
                for cell in row:
                    string_row = string_row + str(cell) + ' '
                print(string_row)

        def print(self):
            print(len(self.slices))
            for slice in self.slices:
                print(slice.print())


if __name__ == '__main__':
    pass
    # pizza = Pizza()
    # pizza.read("small.in")
    # print("max cell", pizza.max_cell)
    # print("min ingredient", pizza.min_ingredient_num)
    #
    # slice = Slice((5, 0), (5, 4))
    #
    # pizza.slice(slice)
    #
    # for s in pizza.slices:
    #     print(s.x, s.y)

        # print(pizza.slices[0].x)

        # input_file = sys.argv[1]
        # pizza = Pizza()
        # pizza.read(input_file)
        #
        # print(pizza.slice())
        # pizza.prin_t()
        # print()
