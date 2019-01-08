import cocos
from consts import *
from cocos.actions import *

class MessageLayer( cocos.layer.Layer ):
    """Transitory messages over worldview

    Full display cycle for transitory messages, with effects and
    optional callback after hiding the message.
    """

    def show_message( self, msg, callback=None ):        
        w,h = (WINDOW_W, WINDOW_H)
        
        self.msg = cocos.text.Label( msg,
            font_size=FONT_SIZE,
            font_name=FONT_NAME,
            anchor_y='center',
            anchor_x='center' )
        self.msg.position=(w/2.0, h)

        self.add( self.msg )

        actions = (
            cocos.actions.Show() + cocos.actions.Accelerate(
                cocos.actions.MoveBy( (0,-h/2.0), duration=0.5)) +
            cocos.actions.Delay(1) +
            cocos.actions.Accelerate(cocos.actions.MoveBy( (0,-h/2.0), duration=0.5)) +
            cocos.actions.Hide()
            )        
        
        if callback:
            actions += cocos.actions.CallFunc( callback )

        self.msg.do( actions )
