import qualified Data.Map

data Property = Flat {level :: Int
                      ,area :: Int
                      ,stages :: Int} | Apartment {level :: Int
                                                  ,area :: Int
                                                  ,stages :: Int
                                                  ,surface :: Int} | House {
  area :: Int} deriving (Show,Eq)
data Object = Flattype | Apartmenttype | Housetype deriving (Eq, Show)
data Query = Type Object | MinArea Int | MaxPrice Int | MaxLevel Int deriving (Eq)


isHouse:: Property -> Bool
isHouse (Flat _ _ _) = False
isHouse (Apartment _ _ _ _) = False 
isHouse (House _) = True

getHouses :: [(Property, Integer)] -> [Property]
getHouses pp = filter isHouse (map fst pp)

getByPrice :: Integer -> [(Property, Integer)] -> [(Property,Integer)]
getByPrice p pp = filter (\x -> ((snd x) < p)) pp

isFlat:: Property -> Bool
isFlat (Flat _ _ _) = True
isFlat (Apartment _ _ _ _) = False
isFlat (House _) = False

getByLevel :: Int -> [(Property, Integer)] -> [(Property,Integer)]
getByLevel l pp = filter (\x -> (isFlat $ fst x) && ((level $ fst x) == l)) pp

getExceptBounds :: [(Property, Integer)] -> [(Property,Integer)]
getExceptBounds pp = filter (\x -> (isFlat $ fst x) && ((level $ fst x)==1 || (level $ fst x) /= (stages $ fst x) )) pp

predicate :: Query -> (Property, Int) -> Bool
predicate (Type t) ((Flat _ _ _),_) = t == Flattype
predicate (Type t) ((Apartment _ _ _ _), _) = t == Apartmenttype
predicate (Type t) ((House _), _) = t == Housetype
predicate (MinArea a) (p, _) = area p >= a
predicate (MaxPrice maxprice) (p, price) = price <= maxprice
predicate (MaxLevel maxlevel) (p, _) = level p < maxlevel

apply :: Query -> [(Property, Int)] -> [(Property, Int)]
apply query products = filter (\p -> predicate query p) products

query :: [Query] -> [(Property, Int)] -> [(Property, Int)]
query queries products = foldr(\q acc -> apply q acc) products queries

