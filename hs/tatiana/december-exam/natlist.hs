natlist :: Integer  -> [Integer]
natlist n = [0..n]

oddlist :: Integer -> [Integer]
oddlist n = filter odd (natlist n)

evenlist :: Integer -> [Integer]
evenlist n = filter even (natlist n)

square :: Integer -> Integer
square n = n * n

squarelist :: Integer -> [Integer]
squarelist n = map square (natlist n)

fact :: Integer -> Integer
fact 0 = 1
fact n = (fact (n - 1)) * n

factlist :: Integer -> [Integer]
factlist n = map fact (natlist n)
{-
toDouble :: Integer -> Double
toDouble n = n * 1.0
-}


isBaseTwo :: Integer -> Bool


basetwolist :: Integer -> [Integer]
basetwolist n = map `elem` (squarelist n)