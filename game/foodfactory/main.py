#!/bin/env python3
'''
Bounces balls around a window and plays noises.

This is a simple demonstration of how pyglet efficiently manages many sound
channels without intervention.

'''

import os
import random
import sys
import math
import pyglet

#from level import Ingredient

from pyglet.gl import *
from consts import config, WINDOW_W, WINDOW_H, SEP_BAR_W, STATUSBAR_W, STATUSBAR_H, GAMEAREA_W, GAMEAREA_H, STATUSBAR_X, GAMEAREA_CENTER_X, GAMEAREA_CENTER_Y, PLATE_SPEED, PLATE_IMG

import gamestate
from gameplay import PlayState
from pause import PauseState
from mainmenu import MenuState

# setup a stack for our game states
states = []

window = pyglet.window.Window(WINDOW_W, WINDOW_H)

keys_pressed = []

@window.event
def on_key_press(key, modifiers):
    if len(states):
        states[-1].on_key_press(key, modifiers, states)

    # elif key in (pyglet.window.key.LEFT, pyglet.window.key.RIGHT):
    #         keys_pressed.append(key)

@window.event
def on_key_release(key, modifiers):
    if len(states):
        states[-1].on_key_release(key, modifiers, states)

@window.event
def on_draw():
    window.clear()
    glClearColor(1, 1, 1, 1)
    glColor3f(1, 0, 0)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    ingredients_batch.draw()
    if len(states):
        states[-1].on_draw()

def update(dt):
##    for ingredient in balls:
##        ball.update(dt, plate)
    if len(states):
        states[-1].update(dt)

# setup the inital states
states.append(PlayState(window))
# game starts paused
states.append(MenuState(window))

pyglet.clock.schedule_interval(update, 1/60.)

ingredients_batch = pyglet.graphics.Batch()

label = pyglet.text.Label('Dish',
                          font_size=14,
                          x=STATUSBAR_X + STATUSBAR_W // 2, y=STATUSBAR_H - 100,
                          anchor_x='center')
# setup()

if __name__ == '__main__':
    pyglet.app.run()
