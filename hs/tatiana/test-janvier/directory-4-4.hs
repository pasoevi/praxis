{- 4 -}

data Directory = File String Int | Directory String [Directory] [String] [Int]

dirAll :: Directory -> [String]
dirAll (File _ _) = [] 
dirAll (Directory _ dd ss _) = ss ++ concat (map dirAll dd)

{- In case the file is not found the function exits abnormally, without a 
good error message. It would be out of scope of this exercise to implement
this feature I think -}

find' :: String -> Directory -> String
find' f (File x _) = if f == x then x else []
find' f (Directory n dd ss _) = if f `elem` ss then n ++ "/" ++ f else (n ++ "/") ++ (head$ [find' f d | d <- dd])

du' (Directory _ dd _ ss) = (sum ss) + sum [du' d | d <- dd]

