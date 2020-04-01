square x = x * x
fib 0 = 1
fib 1 = 2
fib i = fib (i-2) + fib (i-1)

isPositive x = not (x < 0)

signim x = if isPositive x then 1
       else if x < 0 then -1
            else 0