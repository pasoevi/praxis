import cocos
import pyglet
import math
from cocos.actions import *
from consts import *

class Peddle(cocos.sprite.Sprite):
    palette = {}


    def __init__(self, img='peddle.png',
                 x = None,
                 y = None,
                 vel=None):
        super(Peddle, self).__init__(img, anchor=(0, 0))
        if x is None :
            x = WINDOW_W / 2
        if y is None :
            y = self.height / 2
        self.position = x, 0        
        self.paddle_step = self.width / 4

    def update(self, keys_pressed):        
        rect_x, rect_y = math.ceil(self.position[0]), 0
        if len(keys_pressed) > 0:
            if  keys_pressed[0] == pyglet.window.key.LEFT:
                if rect_x >= 0 :
                    if rect_x > self.paddle_step :
                        dpos = self.paddle_step
                    else :
                        dpos = rect_x
                move = MoveBy((-dpos, 0), duration=0.05)
                self.do(move)
            elif keys_pressed[0] == pyglet.window.key.RIGHT:
                if rect_x + self.width < WINDOW_W :
                    if WINDOW_W - (rect_x + self.width) > self.paddle_step :
                        dpos = self.paddle_step
                    else :
                        dpos = WINDOW_W - (rect_x + self.width)
                    move = MoveBy((dpos, 0), duration=0.05)
                    self.do(move)
