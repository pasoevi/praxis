{- 3 -}

data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

leaf x = Node x EmptyTree EmptyTree

exists x EmptyTree = False
exists x (Node a left right)
  | x == a = True
  | x < a = exists x left             
  | x > a = exists x right

add x EmptyTree = leaf x
add x (Node a left right)
  | x == a = Node x left right
  | x < x = Node a (add x left) right
  | x > a = Node a left (add x right)

find' x EmptyTree = error "empty"
find' x (Node a left right)
  | fst x == fst a = snd a
  | x < a = find' x left             
  | x > a = find' x right

toList EmptyTree = []
toList (Node a left right) = a : toList left ++ toList right