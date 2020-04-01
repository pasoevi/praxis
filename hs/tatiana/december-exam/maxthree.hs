max3 :: (Ord a) => a -> a -> a -> a
max3 x y z 
  | x >= y && x >= z  = x
  | y > z             = y
  | otherwise         = z