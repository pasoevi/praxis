nat :: Integer -> [Integer]
nat 0 = 0 : [] 
nat n =  n : nat(n - 1)

revnat n = reverse (nat n)

oddnat n = filter (odd) (nat n)

evennat n = filter (even) (reverse(nat n ))

square [] = []
square (x:xs) = x*x : square xs

natsq 0 = 0
{- natsq n = map square nat n -}