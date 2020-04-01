data Card = Card {rank :: Integer 
                 ,must :: String 
                 } deriving (Show)

isMinor :: Card -> Bool
isMinor (Card c _) = c `elem` [2..10]

getSuit :: Card -> String
getSuit (Card _ s) = s

sameSuit :: [Card] -> Bool
sameSuit cc = all (\x -> (getSuit x) == (getSuit $ head  cc) ) cc

beats :: Card -> Card -> Bool
beats (Card c s) (Card d t) = c > d && s == t

beats2 :: Card -> String -> Card -> Bool
beats2 c k d
  | ((beats c d) && (must d) /= k) = True
  | (must d) /= k && (must c) == k = True
  | (beats c d)  = True
  | otherwise = False

beatsList :: [Card] -> String  -> Card -> [Card]
beatsList cc k c = filter (beats2 c k) cc