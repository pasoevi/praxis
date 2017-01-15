{- 10 -}

data Class = Class {name :: String, methods :: [String], parent :: Class} | Object deriving (Show)
{- Object is the parent of all classes, as in many OOP languages, if a 
class is not a child to any class, it is at least child of this Object 
class. -}

getParent :: Class ->  Class
getParent c = parent c

getPath :: Class -> [Class]
getPath (Class n mm Object) = []
getPath (Class n mm p) = p : getPath p

getMethods :: Class -> [String]
getMethods Object = []
getMethods (Class n mm p) = mm ++ getMethods p

inherit :: String -> Class -> Class
inherit s c = (Class s (getMethods c) c)