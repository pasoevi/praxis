maximum' :: (Ord a) => [a] -> a

maximum' [] = "Error: Maximum of empty list"
maximum' [x] = x
maximum' (x:xs)  
  | x > maxTail = x
  | otherwise =  maxTail
    where maxTail = maximum' xs
          
