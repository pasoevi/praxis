{- 8 -}

import Data.List

data Staff = Staff {name :: String, subordinates :: [Staff]} deriving (Show,Eq)

getSubordinate :: Staff -> [Staff]
getSubordinate (Staff n xx) = xx

getAllSubordinate :: Staff -> [Staff]
getAllSubordinate (Staff s []) = [(Staff s [])]
getAllSubordinate (Staff n subs) = nub (concat $ map getAllSubordinate subs) ++ subs

{- The second argument is the root of the tree to be searched though -}
getBoss :: Staff -> Staff -> Maybe Staff
getBoss a r = find (\x -> a `elem` (subordinates x)) (getAllSubordinate r) 

getList :: Staff -> [(String, [Staff])]
getList s = [(name x, getAllSubordinate x) |  x <- getAllSubordinate s] 