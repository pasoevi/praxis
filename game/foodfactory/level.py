import pyglet
import random
from consts import GAMEAREA_W, GAMEAREA_H


class Level:
    ingredients = []
    collected = []

    def __init__(self, dish_image, ingredients, dish_states):
        self.dish_image = dish_image
        self.ingredients = ingredients
        self.dish_states = dish_states
        self.needed_ingredients = 0
        self.current_step = 1
        self.ingredient_batch = pyglet.graphics.Batch()
        #self.current_ingredients = []

        for ing in self.ingredients:
            if int(ing.grp) == int(self.current_step):
                ing.batch = self.ingredient_batch
                #self.current_ingredients.append(ing)
            if len(ing.steps):
                self.needed_ingredients += 1

    def on_draw(self):
        self.ingredient_batch.draw()

    def update(self, dt, plate):
        #self.current_step += 1

        if len(self.collected) == self.needed_ingredients:
            print('you won!')
            states.pop()

        for ing in self.ingredients :
            if int(ing.grp) == int(self.current_step):
                result = ing.update(dt, plate)
                print('res: '+str(result))
                if result == 1:
                    is_needed = False
                    #for step in ing.steps:
                    if self.current_step in ing.steps :
                        self.collected.append(ing)
                        is_needed = True
                        #break

                    self.ingredients.remove(ing)

                    if not is_needed:
                        print('Arascori aigo')
                        states.pop();

                elif result == -1:
                    self.ingredients.remove(ing)











class Ingredient(pyglet.sprite.Sprite):
    def __init__(self, image, ingredient_id, group, steps, collect_sound = 'collect.wav', drop_sound = 'drop.wav', batch = None):
        self.batch = batch
        self.steps = steps
        self.ingredient_id = ingredient_id
        self.grp = group
        self.ingredient_image = pyglet.resource.image(image)
        x = random.random() * (GAMEAREA_W - self.ingredient_image.width)
        y = GAMEAREA_H - self.ingredient_image.height

        super(Ingredient, self).__init__(self.ingredient_image, x, y)
        self.collect_sound = pyglet.resource.media(collect_sound, streaming=False)
        self.drop_sound = pyglet.resource.media(drop_sound, streaming=False)
        self.dy = 1 * 300
        self.is_collected = False

##    def collect(self):
##        self.set_position(chef.x, chef.y + chef.height + 10)
##        self.is_collected = True

    def update(self, dt, plate):
        #if not self.is_collected:
        result = 0
        if self.y + self.height <= plate.height:
            if self.x >= plate.x and self.x <= plate.x + plate.width:
                #self.collect_sound.play()
                #balls[-1].collect()
                result = 1
            else:
                #self.drop_sound.play()
                #del balls[-1]
                result = -1

        self.y -= self.dy * dt
        return result


class DishState():
    def __init__(self, image, ingredient_ids):
        self.image = image
        self.ingredient_ids = ingredient_ids
