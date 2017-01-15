import Data.List
data Product = Book String String | Tape String | CD String String Integer deriving (Show)


getTitle :: Product -> String
getTitle (Book title _ ) = title
getTitle (Tape title ) = title
getTitle (CD title _ _) = title

{-
on :: (b -> b -> c) -> (a -> b) -> a -> a -> c
f `on` g = \x y -> f (g x) (g y)
-}
getTitles :: [Product]  -> [[Char]]
getTitles pp = map getTitle pp

getAuthor :: Product ->  String
getAuthor (Book title author ) =  author 
getAuthor (Tape title ) = " "
getAuthor (CD title _ _) = " "


bookAuthors :: [Product]  -> [String]
bookAuthors pp = delete " " (map getAuthor pp)

lookupTitle :: String -> [Product] -> Maybe Product
lookupTitle s [] = Nothing
lookupTitle s (p:pp) = if getTitle p == s then Just p else lookupTitle s (tail pp)

lookupTitles :: [String] -> [Product] -> [Product]
lookupTitles ss pp = filter (\x -> (getTitle x) `elem` ss) pp