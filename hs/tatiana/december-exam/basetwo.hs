import Data.List

nat :: Integer -> [Integer]
nat 0 = 0 : [] 
nat n =  sort (n : nat(n - 1))

baseTwo :: Integer -> [Integer]
baseTwo n = [2 ^ p | p <- [0..n]]

isBaseTwo :: Integer -> Bool
isBaseTwo a = if a `elem` (baseTwo a) then True else False

baseTwolist :: Integer -> [Integer]
baseTwolist n = filter isBaseTwo (nat n) 