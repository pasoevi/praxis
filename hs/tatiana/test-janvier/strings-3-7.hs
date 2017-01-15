import Data.Char

data Straction = Clear {caction :: String -> String} | Drop {daction:: Char -> String -> String, char :: Char} | 
                 Replace {raction :: Char -> Char -> String -> String, pat :: Char, c :: Char} |
                 Push {paction :: Char -> String -> String, chartoadd :: Char}

clear :: String -> String
clear s = ""

drop' :: Char -> String -> String
drop' p [] = ""
drop' p s = if (head s) == p then drop' p (tail s) else (head s) : drop' p (tail s)

replace :: Char -> Char -> String -> String
replace p c [] = ""
replace p c s = if (head s) == p then c : replace p c (tail s) else (head s) : replace p c (tail s)

pushInFront :: Char -> String -> String
pushInFront c s = c : s

process :: Straction -> String -> String
process (Clear f) s = f s
process (Drop f char) s = f char s
process (Replace f patt char) s = f patt char s
process (Push f char) s = f char s

processAll :: [Straction] -> String -> String 
processAll actions s = foldl(\acc f -> process f acc) s actions

deleteAll :: String -> String -> String
deleteAll s ss = foldl(\acc c -> processAll [(Drop drop' c)] acc) ss s

