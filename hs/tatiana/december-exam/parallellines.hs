slope :: (Double, Double) -> (Double, Double) -> Double
slope (x1, y1) (x2, y2) = (y2 - y1) / (x2 - x1)


isParallel :: ((Double, Double),(Double, Double)) -> ((Double, Double),(Double, Double)) -> Bool
isParallel (starta, enda) (startb, endb) = slope starta enda == slope startb endb 
