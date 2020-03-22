solve2 :: Double -> Double -> (Bool, Double)
solve2 a b = if a /= 0 then (True, (-b)/a) else (False, 0.0)