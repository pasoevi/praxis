{- 7 -} 

data Trie a = Trie {value ::  a, children :: [(Char, Trie a)]} deriving (Show, Eq)

empty = Trie ' ' []

exists t trie = (value t,  t) `elem` children trie


{- The notion of the Boolean value in the definition of the Trie data
structure is not understandable. It makes insertion of new words very
complicated though. Also, the picture mentioned in this exercise is
not in the pdf file (the only diagram in this file is a graphical
representation of the Binary Search Tree.)

The only way of completing this exercise is to learn the standard 
implementation of the Trie data structure, I see there are quite a
few places for me to look for help (but maybe in future.) -}

insert :: Trie a -> String -> a -> Trie a
insert t [] x = Trie  x (children t)
insert t (k:ks) x = Trie ( value t) (ins (children t) k ks x) where
  ins [] k ks x = [(k, (insert empty ks x))]
  ins (p:ps) k ks x = if fst p == k then (k, insert (snd p) ks x) : ps else p:(ins ps k ks)
