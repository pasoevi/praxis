{- 4.1 -}

average :: [Double] -> Double
average = foldr1 (\x acc -> (x + acc )/2)

scalarMult :: [Integer] -> [Integer] -> [Integer]
scalarMult xs ys = zipWith (*) xs ys

countEven :: [Integer] -> [Integer]
countEven xs = filter even xs

quicksort :: Ord a => [a] -> [a]
quicksort []     = []
quicksort (p:xs) = (quicksort lesser) ++ [p] ++ (quicksort greater)
    where
        lesser  = filter (< p) xs
        greater = filter (>= p) xs


quicksort' :: Ord a => (a -> a -> Bool) -> [a] -> [a]
quicksort' _ []  = []
quicksort' f (p:xs) = (quicksort' lesser) ++ [p] ++ (quicksort' greater)
    where
        lesser  = filter (f) xs
        greater = filter (f) xs


