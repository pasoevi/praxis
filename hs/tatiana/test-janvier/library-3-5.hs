{- 5 -}
data Librarything = Book {author :: String
                          ,title :: String} | Magasin {title :: String
                                                       ,relmonth :: String
                                                        ,relyear :: Int} | Newspaper {title :: String
                                                                                      ,date :: String {--}} deriving (Show,Eq)

isPeriodic :: Librarything -> Bool
isPeriodic (Book _ _) = False
isPeriodic _ = True

isMonthlyPeriodic :: Librarything -> Bool
isMonthlyPeriodic (Magasin _ _ _) = True
isMonthlyPeriodic _ = False

getByTitle :: String -> [Librarything] -> [Librarything]
getByTitle s ll = filter (\obj -> s == (title obj)) ll

getByMonth :: Int -> [Librarything] -> [Librarything]
getByMonth year ll = filter (\obj -> isMonthlyPeriodic obj && (relyear obj) == year) ll

getByMonths :: [String] -> [Librarything] -> [Librarything]
getByMonths months ll = filter (\obj -> isMonthlyPeriodic obj && (relmonth obj) `elem` months) ll

getAuthors :: [Librarything] -> [String]
getAuthors ll = map author $ filter (not . isPeriodic) ll