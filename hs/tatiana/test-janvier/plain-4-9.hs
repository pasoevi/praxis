{- 9 -}

data Point = Point Float Float deriving (Show)
data Area = Rectangle Point Point | Circle {center:: Point, radius :: Float} | Union Area Area | Intersection Area Area

contains :: Point -> Area -> Bool
contains (Point px py) (Rectangle (Point x1 y1) (Point x2 y2)) = (px <= x2 && py <= y2) && (px >= x1 && py >= y1)
contains (Point px py) (Circle (Point x y) r) = (px >= x-r && py >= y-r) && (px <= x+r && py<=y+r)

contains p (Union a b) = contains p a || contains p b
contains p (Intersection a b) = contains p a && contains p b

isRectangular :: Area -> Bool
isRectangular (Rectangle _ _) = True
isRectangular (Union (Rectangle _ _) (Rectangle _ _)) = True
isRectangular (Intersection (Rectangle _ _) (Rectangle _ _)) = True
isRectangular _ = False

area :: Area -> Float
area (Circle _ r) = pi * r ^ 2
area (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)

isEmpty :: Area -> Bool
isEmpty (Rectangle a b) = (area (Rectangle a b)) == 0
isEmpty (Circle p r) = area (Circle p r) == 0
isEmpty (Union a b) = isEmpty a  && isEmpty b
{- isEmpty (Intersection (Rectangle (Point x1 y1) (Point (x2 y2)) (Rectangle (Point x12 y12) (Point x22 y22))) = -}