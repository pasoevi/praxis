import Data.List
data Pict = Jvari | Aguri | Guli | Kvavi deriving (Show, Eq)
data Card = Card {rank :: Integer 
                 ,must :: Pict 
                 } deriving (Show, Eq)

isMinor :: Card -> Bool
isMinor (Card c _) = c `elem` [2..10]

getSuit :: Card -> Pict
getSuit (Card _ s) = s

sameSuit :: [Card] -> Bool
sameSuit cc = all (\x -> (must x) == (getSuit $ head  cc) ) cc

beats :: Card -> Card -> Bool
beats (Card c s) (Card d t) = c > d && s == t

beats2 :: Card -> Pict -> Card -> Bool
beats2 c k d
  | ((beats c d) && (must d) /= k) = True
  | (must d) /= k && (must c) == k = True
  | (beats c d)  = True
  | otherwise = False

beatsList :: [Card] -> Pict  -> Card -> [Card]
beatsList cc k c = filter (beats2 c k) cc

sumScores :: [Card] -> [Int]
sumScores cc = [fromIntegral $ sum $ fst scores , 10 * (length $ snd scores)] where scores = partition (`elem` [2..10] ) (map rank cc)
