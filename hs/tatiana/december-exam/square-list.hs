import Data.List
nat :: Integer -> [Integer]
nat 0 = 0 : [] 
nat n =  sort (n : nat(n - 1))

square :: Integer -> Integer
square x = x * x

natsq :: Integer -> [Integer]

natsq n = sort (map square (nat n))
