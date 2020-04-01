-- 2.7

-- Triangular numbers

triNums :: Integer -> Integer
triNums 1 = 1
triNums n = n + triNums (n-1)

-- 2.8 

pyrNums :: Integer -> Integer
pyrNums 1 = 1
pyrNums n = triNums n + pyrNums (n -1)