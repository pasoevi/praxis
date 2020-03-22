-- 2.1

average :: [Double] -> Double
average (x:xs) = foldr(\acc x -> (acc + x) / 2)x xs

--2.2

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

isTrue :: Bool -> Bool
isTrue = (== True)

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