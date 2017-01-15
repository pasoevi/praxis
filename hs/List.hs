import Data.List
intersperse' :: a -> [a] -> [a] 

intersperse' _ [] = []
intersperse' _ [x] = [x]
intersperse' sep (x:xs)  = x : sep : intersperse' sep xs

flatten' :: [[a]] -> [a]
{- flatten' _ [[x]] = [x] -}
{- flatten' (x:xs) = (head x : tail x) : flatten' (head xs) : flatten' (tail xs) -}
flatten' = foldr(++) []
{-
intercalate :: [a] -> [[c]] -> [d]
intercalate _ [] = [] 
intercalate [] (y:ys) = y: ys
intercalate sep (x:xs) = x : sep : intercalate sep (concat xs)
-}
intercalate xs xss = flatten' (intersperse' xs xss)