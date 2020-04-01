length' xs = sum[1| _ <- xs ]
last' xs = xs!!(length' xs - 1)
last'' xs = th (length' xs -1) xs
last''' xs = th (sum[1| _ <- xs ] -1)  xs



first' xs = xs!!0
th i xs = xs!!i