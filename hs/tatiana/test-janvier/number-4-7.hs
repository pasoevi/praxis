{- 8 -}
data Number = Zero | Next Number deriving (Show)

fromInt :: Integer -> Number
fromInt 0 = Zero
fromInt n = Next (fromInt (n-1))

toInt :: Number -> Integer
toInt Zero = 0
toInt (Next x) = 1 + toInt x

plus :: Number -> Number -> Number
plus x y = fromInt (toInt x + toInt y) {- Sorry, but it's easier -}

mult :: Number -> Number -> Number
mult x y = fromInt (toInt x * toInt y) {- than re-inventing arithmetic 
operators-}

dec :: Number -> Number
dec Zero = Zero  
dec n = fromInt $ ((toInt n) -1)

fact :: Number -> Number
fact Zero = Next Zero
fact n = mult n (dec n)