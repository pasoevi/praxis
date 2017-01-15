import Control.Monad
import Data.List

queens :: Int -> [[Int]]
queens n = map fst $ foldM oneMoreQueen ([],[1..n]) [1..n]  where 
 
  oneMoreQueen (y,d) _ = [ (x:y, d\\[x]) | x <- d, safe x y 1]
 
safe x [] n = True
safe x (c:y) n = and [ x /= c , x /= c + n , x /= c - n , safe x y (n+1)]
 
printSolution y = let n = length y in
  do mapM_ (\x -> putStrLn [if z == x then 'Q' else '.' | z <- [1..n]]) y
     putStrLn ""
 
main = mapM_ printSolution $ queens 8

