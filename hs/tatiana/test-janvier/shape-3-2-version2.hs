import Data.List
data Point = Point Float Float deriving (Show)
data Face = Courier | Lucida | Fixedsys deriving (Show, Eq)
data Font = Font {face :: Face 
                  ,height :: Int 
                  ,width :: Int}  deriving (Show, Eq)
data Shape = Circle Point Float | Rectangle Point Point | Triangle Point Point Point |
             Text Point Font String deriving (Show)
properties :: Font -> (Int,Int)
properties (Font _ w h) = (w,h)
                                             
area :: Shape -> Float
area (Circle _ r) = pi * r ^ 2
area (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)
area (Triangle (Point x1 y1) (Point x2 y2) (Point x3 y3)) = 7 {- !!! -}
area (Text _ f s) = fromIntegral $ (fst letter) * (snd letter) * (length s) where letter = properties f
                                                                                  
isRectangle :: Shape -> Bool
isRectangle (Circle _ _) = False
isRectangle (Rectangle _ _) = True
isRectangle (Triangle _ _ _) = False
isRectangle (Text _ _ _) = False

getRectangles :: [Shape] -> [Shape]
getRectangles ss = filter isRectangle ss

getBound :: Shape -> Shape
getBound (Circle (Point x y) r) = Rectangle (Point (x-r) (y+r)) (Point (x+r) (y-r)) 
getBound (Rectangle (Point x1 y1) (Point x2 y2)) = Rectangle (Point x1 y1) (Point x2 y2)
{- getBound (Triangle (Point x1 y1) (Point x2 y2) (Point x3 y3)) = -}
getBound (Text (Point x y) f s) = Rectangle (Point x yy) (Point (x+fromIntegral((length s)*(width f))) y) where yy = y + fromIntegral(height f)

getBounds :: [Shape] -> [Shape]
getBounds ss = map getBound ss

inRectangle :: Point -> Shape -> Bool
inRectangle (Point x y) (Rectangle (Point x1 y1) (Point x2 y2)) = (x >= x1 && x <= x2 ) && (y >= y1 && y <= y2) {- !!! -}

getFigure :: Point -> [Shape] -> Maybe Shape
getFigure p ss = find (\f -> inRectangle p (getBound f)) ss 

getFigure' p ss = find (inRectangle p) (getBounds ss)
{-
move :: Shape -> Point -> Shape
move -}