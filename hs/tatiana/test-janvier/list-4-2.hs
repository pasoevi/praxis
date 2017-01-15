{- 2 -}
data List a = Nil | Cons a (List a) deriving (Show, Eq)

headList (Cons x _) = x
headList Nil = error "Empty List"

tailList (Cons _ y) = y
tailList Nil = error "Empty list"

lengthList Nil = 0
lengthList (Cons x xx) = 1 + lengthList xx

lastList Nil = error "Empty List"
lastList (Cons x y) = if (lengthList y) == 0 then x else lastList y

nthList 0 (Cons x _) = x
nthList n (Cons x xx) = if (lengthList xx) == n then lastList xx else nthList (n-1) xx

removeNegative (Nil) = Nil
removeNegative (Cons x y) = if x > 0 then (Cons x (removeNegative y)) else removeNegative y

fromList Nil = []
fromList (Cons x y) = x : fromList y

toList [] = Nil
toList (x:xx) = (Cons x (toList xx))