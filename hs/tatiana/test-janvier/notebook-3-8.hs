import Data.List
data Record = Anniversary {name :: String, date :: (String, Int)} | 
              Phonenumber {name :: String, number :: Int} | 
              Assignment {date :: (String, Int), year :: Int, memo :: String} deriving (Show, Eq)

getInfo :: Record -> (String, Int)
getInfo (Phonenumber n num) = (n, num)
getInfo (Anniversary n (mon,day)) = (mon,day)
getInfo (Assignment dat year memo) = dat

isPerson :: Record -> Bool
isPerson (Phonenumber _ _) = True
isPerson (Anniversary _ _) = True
isPerson (Assignment _ _ _ ) = False

notNumber :: Record -> Bool 
notNumber (Phonenumber _ _) = False
notNumber _ = True

getByName :: String -> [Record] -> [(String, Int)]
getByName n rr = foldr(\x acc -> if (name x) == n then getInfo x: acc else acc) [] (filter isPerson rr)

getByLetter :: Char -> [Record] -> [String]
getByLetter c rr = foldr(\x acc -> if (head $ name x) == c then (name x) : acc else acc) [] (filter isPerson rr)

isNeededAssignment :: (String, Int, Int) -> Record -> Bool
isNeededAssignment (mon, day, year) (Anniversary x dat) = (mon, day) == dat
isNeededAssignment (mon, day, year) (Assignment dat yy memo) = (mon, day, year) == (fst dat, snd dat, year)

isAnniv :: Record -> Bool
isAnniv (Anniversary _ _) = True 
isAnniv _ = False

getNumber :: Record -> [Record] -> Record
getNumber n rr = head $ (foldr(\x acc -> if (name x) == (name n) && (not (notNumber x)) then  x: acc else acc) [] (filter isPerson rr))

getAssignment :: (String, Int, Int) -> [Record] -> [Record]
getAssignment dat rr =foldr(\x acc -> if (isAnniv x) && (isNeededAssignment dat x) then getNumber x rr : acc else acc) (filter (\x -> isNeededAssignment dat x) (filter notNumber rr) ) rr
