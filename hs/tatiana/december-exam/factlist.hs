import Data.List

nat :: Integer -> [Integer]
nat 0 = 0 : [] 
nat n =  sort (n : nat(n - 1))

fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n - 1) 

factlist :: Integer -> [Integer] 
factlist n = map fact (nat n)