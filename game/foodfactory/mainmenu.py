import pyglet

from gamestate import GameState, MENU_STATE_ID

class MenuState(GameState):
    def __init__(self, window):
        self.label = pyglet.text.Label('Press ENTER to start.',
                                  font_name='Times New Roman',
                                  font_size=36,
                                  x=window.width//2, y=window.height//2,
                                  color=(155, 55, 24, 255),
                                  anchor_x='center', anchor_y='center')
        self.id = MENU_STATE_ID

    def on_draw(self):
        self.label.draw()

    def update(self, dt):
        pass

    def on_key_press(self, key, modifiers, states):
        pass

    def on_key_release(self, key, modifiers, states):
        if key == pyglet.window.key.ENTER:
            states.pop()        
        


    
