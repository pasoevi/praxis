import Data.List

multThree :: (Num a) => a -> a -> a -> a

multThree x y z = x * y * z

multWithNine = multThree 9
multWithEighteen = multWithNine 2 

comparewithTen :: (Num a, Ord a) => a -> Ordering
comparewithTen x = compare x 10

applyTwice :: (a -> a) -> a -> a
applyTwice f x = f(f x)

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' _ [] _ = []
zipWith' _ _ [] = []
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys

flip' :: (a -> b -> c) -> b -> a -> c
flip' f = g
          where g x y = f y x

map' :: (a -> b) -> [a] -> [b]
map' _ [] = [] 
map' f (x:xs) = f x : map f xs

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' p (x:xs) 
  | p x = x : filter' p xs
  | otherwise = filter p xs
                
largestDivisible :: (Integral a) => a
largestDivisible = head (filter' p [100000, 99999..])
                   where p x = x `mod` 3829 == 0
                         
