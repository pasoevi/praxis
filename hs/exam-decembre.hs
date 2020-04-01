-- 1.1 

(("G", 4), "Paraplui", [44.4, 77.4])

-- 1.2 

[(33.3, False, ("Samwise", [88,9,7]))]

-- 1.3 

([4], [44.78, 7], [(False, "R")]) 

-- 1.4

[[[(4, False)]]]

-- 1.5 

((("B", "D"), "G"), "Penguin")

-- 1.6 

(([1.2, 7.7], [False, False]), [4, 7])

-- 1.7 

-- Error: A List can't contain the elements of different type


-- 1.8 

(False, ([True], [4]))

-- 1.9 

[([True], [4.4])]

-- 1.10 

[([5], "C")]

--------------------------------------

-- 2.1 

max3 :: (Ord a) => a -> a -> a -> a
max3 x y z 
  | x >= y && x >= z  = x
  | y > z             = y
  | otherwise         = z
                        
-- 2.2

min3 :: (Ord a) => a -> a -> a -> a
min3 x y z 
  | x <= y && x <= z  = x
  | y < z             = y
  | otherwise         = z


-- 2.3

sort2 :: (Ord a) => a -> a -> (a,a)
sort2 x y 
  | x < y = (x, y)
  | otherwise = (y, x)
                
-- 2.4 

bothTrue :: Bool -> Bool -> Bool
bothTrue a b = min a b

-- 2.5

solve2 :: Double -> Double -> (Bool, Double)
solve2 a b = if a /= 0 then (True, (-b)/a) else (False, 0.0)

-- 2.6

slope :: (Double, Double) -> (Double, Double) -> Double
slope (x1, y1) (x2, y2) = (y2 - y1) / (x2 - x1)


isParallel :: ((Double, Double),(Double, Double)) -> ((Double, Double),(Double, Double)) -> Bool
isParallel (starta, enda) (startb, endb) = slope starta enda == slope startb endb 

-- 2.7

square :: Double -> Double
square x = x * x

distance :: (Double, Double) -> (Double, Double) -> Double
distance (x1, y1) (x2, y2) = sqrt (square (x2 - x1) + square (y2 - y1))

isIncluded :: ((Double, Double), Double) -> ((Double, Double), Double) -> Bool
isIncluded ((x1, y1), r1) ((x2, y2), r2) = r1 >= abs (distance (x1, y1) (y1, y2)) + r2


-- 2.8

import Data.List

square :: Double -> Double
square x = x * x

distance :: (Double, Double) -> (Double, Double) -> Double
distance (x1, y1) (x2, y2) = sqrt (square (x2 - x1) + square (y2 - y1))

sides :: (Double, Double) -> (Double, Double) -> (Double, Double) -> [Double]
sides (x1, y1) (x2, y2) (x3, y3) = reverse (sort [distance a b | (a, b) <- [((x1, y1),(x2, y2)), ((x1, y1), (x3, y3)), ((x2,y2), (x3, y3))]])

isRectangular :: (Double, Double) -> (Double, Double) -> (Double, Double) -> Bool
isRectangular (x1,y1) (x2, y2) (x3, y3) = if square (head (sides (x1, y1) (x2, y2) (x3, y3))) == sum (map square (tail (sides (x1, y1) (x2, y2) (x3, y3)))) then True else False

-----------------------------------------------------------------------------

-- Lab 2 ---

import Data.List

-- 1.1

nat :: Integer -> [Integer]
nat 0 = 0 : [] 
nat n =  sort (n : nat(n - 1))

-- 1.2 

oddnat n = filter (odd) (nat n)

-- 1.3

evennat n = filter (even) (nat n )

-- 1.4

square :: Integer -> Integer
square x = x * x

natsq :: Integer -> [Integer]
natsq n = sort (map square (nat n))


-- 1.5

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1) 

factlist :: Integer -> [Integer] 
factlist n = map fact (nat n)

-- 1.6

baseTwo :: Integer -> [Integer]
baseTwo n = [2 ^ p | p <- [0..n]]

isBaseTwo :: Integer -> Bool
isBaseTwo a = if a `elem` (baseTwo a) then True else False

baseTwolist :: Integer -> [Integer]
baseTwolist n = filter isBaseTwo (nat n) 

-- 1.7

square :: Double -> Double
square x = x * x

distance :: (Double, Double) -> (Double, Double) -> Double
distance (x1, y1) (x2, y2) = sqrt (square (x2 - x1) + square (y2 - y1))

isIncluded :: ((Double, Double), Double) -> ((Double, Double), Double) -> Bool
isIncluded ((x1, y1), r1) ((x2, y2), r2) = r1 >= abs (distance (x1, y1) (y1, y2)) + r2


-- 1.8
(Promblem with Hugs with lesser float precision. Works with GHI

square :: Double -> Double
square x = x * x

distance :: (Double, Double) -> (Double, Double) -> Double
distance (x1, y1) (x2, y2) = sqrt (square (x2 - x1) + square (y2 - y1))

sides :: (Double, Double) -> (Double, Double) -> (Double, Double) -> [Double]
sides (x1, y1) (x2, y2) (x3, y3) = reverse (sort [distance a b | (a, b) <- [((x1, y1),(x2, y2)), ((x1, y1), (x3, y3)), ((x2,y2), (x3, y3))]])

isRectangular :: (Double, Double) -> (Double, Double) -> (Double, Double) -> Bool
isRectangular (x1,y1) (x2, y2) (x3, y3) = if square (head (sides (x1, y1) (x2, y2) (x3, y3))) == sum (map square (tail (sides (x1, y1) (x2, y2) (x3, y3)))) then True else False


--------------------------------------------------------

-- Lab 2

-- 1.1

nat :: Integer -> [Integer]
nat 0 = 0 : [] 
nat n =  sort (n : nat(n - 1))


-- 1.2

oddnat :: Integer -> [Integer]

oddnat n =  filter odd (nat n)

-- 1.2 

evennat :: Integer -> [Integer]
evennat n = filter even (nat n)

-- 1.3 

squarelist :: Integer -> [Integer]
squarelist n = map square (nat n)

-- 1.5

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1) 

factlist :: Integer -> [Integer] 
factlist n = map fact (nat n)

-- 1.6

baseTwo :: Integer -> [Integer]
baseTwo n = [2 ^ p | p <- [0..n]]

isBaseTwo :: Integer -> Bool
isBaseTwo a = if a `elem` (baseTwo a) then True else False

baseTwolist :: Integer -> [Integer]
baseTwolist n = filter isBaseTwo (nat n) 

-- 1.7 

triNums :: Integer -> Integer
triNums 1 = 1
triNums n = n + triNums (n-1)

-- 1.8 

pyrNums :: Integer -> Integer
pyrNums 1 = 1
pyrNums n = triNums n + pyrNums (n -1)

-----------------

-- 2.1

average :: [Double] -> Double
average (x:xs) = foldr(\acc x -> (acc + x) / 2)x xs

-- 2.2

takeN :: Int -> [Double] -> [Double]
takeN _ [] = []
takeN 0 _ = []
takeN n (x:xs) = x : take (n - 1) xs

-- 2.3 

zipSum :: [Double] -> [Double] -> [Double]
zipSum xs ys = zipWith (+) xs ys

-- 2.4 

badNeighbours :: Integer -> [Integer] -> Bool
badNeighbours x [] = False
badNeighbours x (y:_) = if ((even x) && (odd y)) || ((odd x) && (even y)) then True else False

displace :: [Integer] -> [Integer]
displace [] = []
displace (x:xs) = if (badNeighbours x xs) then (head xs) : x : (displace (tail xs)) else x : displace xs

-- 2.5

twopow :: Integer -> Integer
twopow 0 = 1
twopow 1 = 2
twopow n | even n = twopow (n`quot`2) * twopow (n`quot`2) | otherwise = (2 * twopow (n`quot`2) * twopow (n`quot`2))

-- 2.6

notOdd :: Integer -> Bool
notOdd x = if odd x then False else True

removeOdd :: [Integer] -> [Integer]
removeOdd xs = filter notOdd xs

-- 2.7

nonEmpty :: String -> Bool
nonEmpty s = length s > 0

removeEmpty :: [String] -> [String]
removeEmpty xs = filter nonEmpty xs

-- 2.8 

countTrue :: [Bool] -> Int
countTrue xs = length (filter (==True) xs)

-- 2.9

negateNegative :: Integer -> Integer
negateNegative x = if x < 0 then (-1) * x else x

makePositive :: [Integer] -> [Integer]
makePositive = map negateNegative


-- 2.10

delete' :: Char -> String -> String
delete' _ [] = []
delete' c (x:xs) = if c == x then delete' c xs else x : delete' c xs

-- 2.11

substitute :: Char -> Char -> String -> String
substitute _ _ [] = []
substitute c p (x:xs) = if x == c then p : substitute c p xs else x: substitute c p xs