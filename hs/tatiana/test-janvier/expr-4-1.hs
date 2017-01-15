{- import Expr -}

data Expr = Const Integer | Var String | Add Expr Expr | Mult Expr Expr deriving (Show, Eq)

{-I might be wrong here about the differentiation. Haskell code is
correct though. -}

diff :: Expr -> Expr -> Expr
diff (Const _) _ = Const 0
diff (Var x) (Var w)  = if x == w then Const 0 else Var x
diff (Add x y) (Var w) = Add (diff x (Var w)) (diff y (Var w))
diff (Mult x y) (Var w) = Add (Mult (diff x (Var w)) y) (Mult x (diff y (Var w))) 

simplify :: Expr -> Expr
simplify (Add x (Const 0)) = x
simplify (Add (Const 0) x) = x
simplify (Mult x (Const 1)) = x
simplify (Mult (Const 1) x) = x
simplify (Mult x (Const 0)) = Const 0
simplify (Mult (Const 0) x) = Const 0
{- ... -}

{- Support for grouping by parenthesis is not fully implemented. Might be 
improved later -}

toString :: Expr -> String
toString (Var x) = x
toString (Const x) = show x
toString (Add x y) = (toString x) ++ "+" ++ (toString y)
toString (Mult x y) = "(" ++ (toString x) ++ ")" ++ "*(" ++ (toString y) ++ ")"

lookupVar :: String -> [(String, Integer)] -> Integer
lookupVar v (x:xx) = if fst x == v then snd x else lookupVar v xx

eval' :: Expr -> [(String, Integer)] -> Integer
eval' (Const x) _ = x
eval' (Add x y) vars = (eval' x vars ) + (eval' y vars)
eval' (Mult x y) vars = (eval' x vars) * (eval' y vars)
eval' (Var x) (v:vv) = if fst v == x then snd v else lookupVar x vv