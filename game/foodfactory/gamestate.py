PAUSE_STATE_ID = 0
PLAY_STATE_ID = 1
MENU_STATE_ID = 2

class GameState:
    def on_enter():
        pass

    def on_exit():
        pass

    def on_draw():
        pass

    def on_update(dt):
        pass

    def on_key_press(key, modifiers):
        pass

    def on_key_release(key, modifiers):
        pass
