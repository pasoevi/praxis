import configparser

conffile = 'foodfactory.conf'

config = configparser.ConfigParser()
config.sections()
config.read(conffile)

# Window
WINDOW_W = config.getint('window', 'width')
WINDOW_H = config.getint('window', 'height')


# World
SEP_BAR_W = config.getint('world', 'separator_width')
STATUSBAR_W = WINDOW_W // 4
STATUSBAR_H = WINDOW_H
GAMEAREA_W = WINDOW_W - STATUSBAR_W - SEP_BAR_W
GAMEAREA_H = WINDOW_H
STATUSBAR_X = GAMEAREA_W + SEP_BAR_W
GAMEAREA_CENTER_X = WINDOW_W // 2
GAMEAREA_CENTER_Y = WINDOW_H // 2
DEFAULT_DATADIR = config.get('world', 'datadir')
LEVEL_WORD = config.get('world', 'level_word')


# Plate
PLATE_SPEED = config.getint('plate', 'speed')
PLATE_IMG = config.get('plate', 'img')


