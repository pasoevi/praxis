import cocos
from cocos import collision_model as cm
from cocos import euclid as eu
from consts import SOUND_BLOCK_BREAK
import pyglet


class Block(cocos.sprite.Sprite):
    def __init__(self, x, y, lives=1, img='block.png'):
        super(Block, self).__init__(img, anchor=(0, 0))
        self.lives = lives
        self.position = x, y
        self.cshape = cm.AARectShape(
            eu.Vector2(x+self.width/2, y+self.height/2),
            self.width / 2,
            self.height / 2
        )        
        self.effect = pyglet.media.load('break.wav')
    def was_hit(self):
        self.lives -= 1
        self.effect.play()
        return self.lives
