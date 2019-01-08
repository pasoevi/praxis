import pprint
import pyglet
from pause import PauseState
import math
from gamestate import GameState, PLAY_STATE_ID
from consts import GAMEAREA_CENTER_X, GAMEAREA_CENTER_Y, PLATE_SPEED, STATUSBAR_X, STATUSBAR_W, STATUSBAR_H, GAMEAREA_W
from worldbuilder.world import World

class Plate(pyglet.sprite.Sprite):
    def __init__(self, img='graphics/plate.png'):
        plate_img = pyglet.resource.image(img)
        width = plate_img.width
        height = plate_img.height
        x = GAMEAREA_CENTER_X - plate_img.width // 2
        y = 0
        dx = PLATE_SPEED
        super(Plate, self).__init__(plate_img, x, y)        
        # self.collect_sound = pyglet.resource.media(COLLECT_SOUND, streaming=False)

    def update(self, keys_pressed, dt):
        rect_x, rect_y = math.ceil(self.position[0]), 0
        if len(keys_pressed) > 0:
            if  keys_pressed[0] == pyglet.window.key.LEFT:
                if rect_x >= 0 :
                    if rect_x > PLATE_SPEED:
                        self.dx = PLATE_SPEED
                    else :
                        self.dx = rect_x
                self.x -= self.dx
            elif keys_pressed[0] == pyglet.window.key.RIGHT:
                if rect_x + self.width < GAMEAREA_W :
                    if GAMEAREA_W - (rect_x + self.width) > PLATE_SPEED :
                        self.dx = PLATE_SPEED
                    else :
                        self.dx = GAMEAREA_W - (rect_x + self.width)
                    self.x += self.dx


class PlayState(GameState):
    def __init__(self, window):
        self.window = window
        self.plate = Plate()
        chef_img = pyglet.resource.image('graphics/chef.png')
        self.chef = pyglet.sprite.Sprite(chef_img, x=(STATUSBAR_X + STATUSBAR_W // 2), y=10)
        self.id = PLAY_STATE_ID
        self.keys_pressed = []
        self.world = World('guria')
        self.level = self.world.get_level(1)

    def on_draw(self):
        # draw status bar/gamearea separator
        pyglet.graphics.draw(2, pyglet.gl.GL_LINES,
                         ('v2i', (STATUSBAR_X, 0, STATUSBAR_X, STATUSBAR_H)))
        self.plate.draw()
        self.chef.draw()
        self.level.on_draw()

    def update(self, dt):
        self.plate.update(self.keys_pressed, dt)
        self.level.update(dt, self.plate)
        

    def on_key_press(self, key, modifiers, states):
        if key in (pyglet.window.key.LEFT, pyglet.window.key.RIGHT):
            self.keys_pressed.append(key)
            
    def on_key_release(self, key, modifiers, states):
        if key == pyglet.window.key.SPACE:
            states.append(PauseState(self.window))
        elif key in (pyglet.window.key.LEFT, pyglet.window.key.RIGHT):
            self.keys_pressed.remove(key)
