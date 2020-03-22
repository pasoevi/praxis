data Tree a = Null | Node (Tree a) a (Tree a)

sum_tree :: Tree Integer -> Integer

sum_tree Null = 0
sum_tree (Node left val right) = sum_tree left + val + sum_tree right

t:: Tree Integer
t = Node (Null 4 null)
