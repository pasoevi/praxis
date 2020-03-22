min3 :: (Ord a) => a -> a -> a -> a
min3 x y z 
  | x <= y && x <= z  = x
  | y < z             = y
  | otherwise         = z