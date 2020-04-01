square :: Double -> Double
square x = x * x

max3 :: (Ord a) => (a, a, a) -> a
max3 (x, y, z)
  | x >= y && x >= z  = x
  | y > z             = y
  | otherwise         = z

distance :: (Double, Double) -> (Double, Double) -> Double
distance (x1, y1) (x2, y2) = sqrt (square (x2 - x1) + square (y2 - y1))

isIncluded :: ((Double, Double), Double) -> ((Double, Double), Double) -> Bool
isIncluded ((x1, y1), r1) ((x2, y2), r2) = r1 >= abs (distance (x1, y1) (y1, y2)) + r2
{-
sides :: (Double, Double) -> (Double, Double) -> (Double, Double) -> (Double, Double, Double)
sides (x1, y1) (x2, y2) (x3, y3)
     | snd (sortSides ((x1, y1), ((x2, y2  h)) ((x1,y1), (x3, y3)) > distance (x1, y1) (x3, y3) && distance (x2, y2) (x3, y3) = distance (x1, y1) (x2, y2)
     | distance (x1, y1) (x3, y3) > distance (x2, y2) (x3, y3) = distace (x1,y1) (x3, y3)
     | otherwise = distance (x2, y2) (x3, y3)
-}
{-
sortSides :: ((Double, Double), (Double, Double)) -> ((Double, Double), (Double, Double)) -> (Double, Double)
sortSides (a, b) (c, d)  = if distance a b < distance c d then ((distance a b), (distance c d)) else ((distance c d), (distance a b))
-}

first :: (Double, Double, Double) -> Double
first (a, _, _) = a

second :: (Double, Double, Double) -> Double
second (_, b, _) = b

third :: (Double, Double, Double) -> Double
third (_, _, c) = c

sides :: (Double, Double) -> (Double, Double) -> (Double, Double) -> [Double]
sides (x1, y1) (x2, y2) (x3, y3) 
  | (distance (x1, y1) (x2, y2)) > (distance (x1, y1) (x3, y3)) && (distance (x1, y1) (x2, y2)) > (distance (x2, y2) (x3, y3)) = [(distance (x1, y1) (x2, y2)), (distance (x1, y1) (x3, y3)), (distance (x2, y2) (x3, y3))]
                                                                                                                                 | (distance (x1, y1) (x3, y3)) > (distance (x2, y2) (x3, y3)) = [(distance (x1, y1) (x3, y3)), (distance (x2, y2) (x3, y3)), (distance (x1, y1) (x2, y2))]
                                                                                                                                                                                                | otherwise = [(distance (x2, y2) (x3, y3)), (distance (x1, y1) (x3, y3)), (distance (x1, y1) (x2, y2))]
{-
squares ::  (Double, Double) -> (Double, Double) -> (Double, Double) -> (Double, Double, Double)
squares (x1, y1) (x2, y2) (x3, y3) = (square (first side), square (second side), square (third side))  where side = sides (x1, y1) (x2, y2) (x3, y3)
-}


isRectangular :: (Double, Double) -> (Double, Double) -> (Double, Double) -> Bool
isRectangular (x1, y1) (x2, y2) (x3, y3) = if square (head side) == sum (map square (tail side)) then True else False where side = sides (x1, y1) (x2, y2) (x3, y3)
