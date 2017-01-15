import Data.List
data Assignment = Lab {subject :: String ,number :: Int} | 
                  Graphical {subject :: String} |
                  Referat {subject :: String, theme :: String} deriving (Show, Eq)

getByTitle :: String -> [(Assignment,Maybe Int)] -> Maybe (Assignment, Maybe Int)
getByTitle s aa = find (\x ->  s == (subject $ fst  x) && snd x == Nothing) aa

getRefTheme :: Assignment -> String
getRefTheme (Referat s t) = t
getRefTheme _ = ""

getReferats :: [(Assignment, Maybe Int)] -> [String]
getReferats aa = filter (/="" ) (map getRefTheme (map fst aa))

getTitle :: Assignment -> String
getTitle a = subject a

notCompleted :: (Assignment,Maybe Int) -> Bool
notCompleted (_, c) = c == Nothing

notCompletedFor :: Maybe Int -> (Assignment,Maybe Int) -> Bool
notCompletedFor w (_, Nothing) = True
notCompletedFor w (_, c) = c > w

getRest :: [(Assignment, Maybe Int)] -> [String]
getRest aa = map getTitle (map fst (filter notCompleted aa))

getRestForWeek :: Maybe Int -> [(Assignment, Maybe Int)] -> [Assignment]
getRestForWeek w aa = map fst (filter (\x -> notCompletedFor w x) aa)

getCompletedIn :: Maybe Int -> [(Assignment, Maybe Int)] -> [Assignment]
getCompletedIn w aa =  map fst (filter (\x ->  w == snd x) aa)

getWeeks :: [(Assignment, Maybe Int)] -> [Maybe Int]
getWeeks aa = map snd aa

getPlot :: [(Assignment, Maybe Int)] -> [(Maybe Int, [Assignment])]
getPlot aa = nub [(a,[b | b  <- getCompletedIn a aa]) | a <- getWeeks aa]