import memoization

@memoization.memoize
def fib(x):
    if x in (0, 1):
        return x
    else:
        return fib(x-2) + fib(x-1)
@memoization.memoize
def fibgen(x):
    a, b = 0,1
    while a < x:
        yield a
        a, b = b, a + b
