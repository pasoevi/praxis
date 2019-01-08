import configparser

PROGRAM_NAME = "Ice Blocks"

conffile = 'iceblocks.conf'

config = configparser.ConfigParser()
config.sections()
config.read(conffile)

# View
FONT_NAME = config.get('view', 'font_name')
FONT_SIZE = config.getint('view', 'font_size')

# Window
WINDOW_W = config.getint('window', 'width')
WINDOW_H = config.getint('window', 'height')
RESIZABLE = config.getboolean('window', 'resizable')

# Bindings
KEY_LEFT = config.get('bindings', 'key.LEFT')
KEY_RIGHT = config.get('bindings', 'key.RIGHT')

# World
BALL_SPEED = config.getint('world', 'ballspeed')
LIVES = config.getint('world', 'live')

# Palette
BG_COLOR = eval(config.get('palette', 'bg'))

# Audio
AUDIO_BACKEND = config.get('audio', 'backend')
SOUND_BLOCK_BREAK = config.get('audio', 'block_break')
