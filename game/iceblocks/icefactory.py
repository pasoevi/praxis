from block import Block
import itertools
from consts import WINDOW_H, WINDOW_W


def flatten(listOfLists):
    "Flatten one level of nesting"
    return itertools.chain.from_iterable(listOfLists)


class Row:
    def __init__(self, numblocks, startpos, blockw):
        """
        There are two kinds of rows:
            * one with no gaps
            * and rows with arbitrary empty spaces in place of blocks
        """
        x, y = startpos
        positions = []
        if type(numblocks) == type(1):
            # We are producing a simple row, with no gaps
            positions = [(x + i * blockw, y) for i in range(numblocks)]
        else:
            # we were given a tuple of zeros and ones. zero means no block
            i = 0
            for b in numblocks:
                if b == 1:
                    positions.append((x + i * blockw, y))
                i += 1
        self.blocks = [Block(*p) for p in positions]


class Level:
    def __init__(self, rows, level):
        nestedBlocks = [row.blocks for row in rows]
        self.blocks = flatten(nestedBlocks)
        self.level = level


class BlockFactory:
    def __init__(self):
        self.levels = ((10, 9, 8, 7, 6), (10, 9, 8, 9, 10),
                      (6, 7, 8, 9, 10), (8, 9, 10, 9, 8), (9, 5, 7, 8, 6))
        #self.levels = (((1, 0, 0, 1), (1, 1, 1, 1)), ((1, 1, 1), (1, 0, 1)))

    def get_level(self, n):
        if n >= len(self.levels):            
            raise Exception('No More Levels!', 0)
        block = Block(1, 1)
        blockw = block.width
        voffset = 40

        rows = []
        blockNums = self.levels[n]
        i = 1
        for m in blockNums:
            if type(m) == type(1):
                startpos = ((WINDOW_W - m * blockw) / 2, WINDOW_H - i * voffset)
                rows.append(Row(m, startpos, blockw))
                i += 1
            else:
                startpos = ((WINDOW_W - len(m) * blockw) / 2, WINDOW_H - i * voffset)
                rows.append(Row(m, startpos, blockw))
                i += 1

        return Level(rows, n)
