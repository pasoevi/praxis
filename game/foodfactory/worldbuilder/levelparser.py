import xml.etree.ElementTree as ET
import level
import pprint
import os

XML_ID = 'id'
XML_GROUP = 'group'
XML_NAME = 'name'
XML_IMAGE = 'image'
XML_STEPS = 'steps'
XML_INGREDIENT_IDS = 'ingredientIDs'
XML_INGREDIENTST = 'ingredients'
XML_DISH_STATES = 'dishStates'
XML_DISH_IMAGE = 'dishImage'

class LevelParser:
    def __init__(self, level_file):
        self.tree = ET.parse(level_file)
        self.root = self.tree.getroot()

    def _obtain_ingredients(self, elem):
        ingredients = []
        for ing in elem:
            name = None
            image = None
            steps = []
            ingredient_id = ing.get(XML_ID)
            group = ing.get(XML_GROUP)
            for child in ing:
                if child.tag == XML_NAME:
                    name = child.text
                elif child.tag == XML_IMAGE:
                    image = child.text
                elif child.tag == XML_STEPS:
                    for step in child:
                        steps.append(step.text)
            print('surati '+image)
            print(os.getcwd())
            ingredient = level.Ingredient(image, ingredient_id, group, steps)
            ingredients.append(ingredient)
        return ingredients

    def _obtain_dish_image(self, elem):
        return elem.text


    def _obtain_dish_states(self, elem):
        dish_states = []
        for dish_state in elem:
            image = None
            ingredient_ids = []
            for child in dish_state:
                if child.tag == XML_IMAGE:
                    image = child.text
                elif child.tag == XML_INGREDIENT_IDS:
                    for ingredientID in child:
                        ingredient_ids.append(ingredientID.text)
            dish_states.append(level.DishState(image, ingredient_ids))

    def parse_level(self):
        dish_image = None
        ingredients = None
        dish_states = None
        for child in self.root:
            if child.tag == XML_INGREDIENTST:
                ingredients = self._obtain_ingredients(child)
            elif child.tag == XML_DISH_IMAGE:
                dish_image = self._obtain_dish_image(child)
            elif child.tag == XML_DISH_STATES:
                dish_states = self._obtain_dish_states(child)
        pprint.pprint(ingredients)
        print(dish_image)
        return level.Level(dish_image, ingredients, dish_states)



