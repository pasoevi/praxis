sum' :: (Num a) => [a] -> a
sum' xs = foldl(\acc x -> acc + x) 3 xs

elem' :: (Eq a) => a -> [a] -> Bool
elem' y ys = foldl(\acc x -> if x == y then True else acc) False ys

map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr(\x acc -> f x : acc) [] xs

maximum' :: (Ord a) => [a] -> a
maximum' = foldr1(\x acc -> if x > acc then x else acc)

reverse' :: [a] -> [a]
reverse' = foldl(\acc x -> x : acc) []

product' :: (Num a) => [a] -> a
{- product' = foldr1(\x acc -> x * acc) -}
product' = foldr1(*)

filter' :: (a -> Bool) -> [a] -> [a]
filter' p = foldr(\x acc -> if p x then x : acc else acc) []

head' :: [a] -> a
head' (x:xs) = x

last' :: [a] -> a
last' = foldl1(\_ x -> x)

reverse'' :: [a] -> [a]
reverse'' = foldl(flip(:)) []
