{- 5 -}

import Data.List
data Prop = Symbol String Bool | Conj Prop Prop | Disj Prop Prop | Prop Bool deriving (Show,Eq)

vars :: Prop -> [String]
vars (Symbol s b) = [s]
vars (Conj a b) = nub (vars a ++ vars b)
vars (Disj a b) = nub (vars a ++ vars b)
vars (Prop a) = []

findValue :: String -> [(String, Bool)] -> Bool
findValue s vv = snd $ head (filter (\x -> fst x == s) vv)

truthValue :: Prop -> [(String, Bool)] -> Bool
truthValue (Symbol s _) vv = findValue s vv
truthValue (Prop b) _ = b
truthValue (Conj a b) vv = (truthValue a vv) && (truthValue b vv)
truthValue (Disj a b) vv = (truthValue a vv) || (truthValue b vv)

tautology :: Prop -> Bool
tautology (Prop b) = b
tautology (Symbol _ v) = v
tautology (Conj (Symbol x1 _) (Symbol x2 _)) = x1 == x2
tautology (Conj a b) = tautology a && tautology b
tautology (Disj (Symbol x1 _) (Symbol x2 _)) = x1 == x2
tautology (Disj a b) = tautology a || tautology b

