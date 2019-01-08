from consts import DEFAULT_DATADIR, LEVEL_WORD
from worldbuilder.levelparser import LevelParser
import os
import random

class World:
    def __init__(self, world_name, datadir=DEFAULT_DATADIR):
        self.world_dir = os.path.join(datadir, world_name)
        
    def get_level(self, level_n):
        levels_dir = os.path.join(self.world_dir, LEVEL_WORD + str(level_n))
        level_file = random.choice(os.listdir(levels_dir))
        parser = LevelParser(os.path.join(levels_dir, level_file))        
        return parser.parse_level()

    
