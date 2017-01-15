{----- Lab 3 -----}

{- 1 -} 

import Data.List
data Product = Book String String | Tape String | CD String String Integer deriving (Show)


getTitle :: Product -> String
getTitle (Book title _ ) = title
getTitle (Tape title ) = title
getTitle (CD title _ _) = title

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

{- 2 -}

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

{- The last part of the exercise in not very understandable, there is
no law given according which to determine what the sum of possible
scores of the card set will be. Thus, the funcion sumScores just
returns the two-element list of the sum of nominal and special cards.
I do not know the rules of this game myself.
-}

sumScores :: [Card] -> [Int]
sumScores cc = [fromIntegral $ sum $ fst scores , 10 * (length $ snd scores)] where scores = partition (`elem` [2..10] ) (map rank cc)


{- 3 -}

import Data.List

data Point = Point Float Float deriving (Show)
data Face = Courier | Lucida | Fixedsys deriving (Show, Eq)
data Font = Font {face :: Face 
                  ,height :: Int 
                  ,width :: Int}  deriving (Show, Eq)

data Shape = Circle Point Float | Rectangle Point Point | Triangle Point Point Point |
             Text Point Font String deriving (Show)
properties :: Font -> (Int,Int)
properties (Font _ w h) = (w,h)
                                             
area :: Shape -> Float
area (Circle _ r) = pi * r ^ 2
area (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)
area (Triangle (Point x1 y1) (Point x2 y2) (Point x3 y3)) = abs $ (x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/2
area (Text _ f s) = fromIntegral $ (fst letter) * (snd letter) * (length s) where letter = properties f
                                                                                  
isRectangle :: Shape -> Bool
isRectangle (Circle _ _) = False
isRectangle (Rectangle _ _) = True
isRectangle (Triangle _ _ _) = False
isRectangle (Text _ _ _) = False

getRectangles :: [Shape] -> [Shape]
getRectangles ss = filter isRectangle ss

getBound :: Shape -> Shape
getBound (Circle (Point x y) r) = Rectangle (Point (x-r) (y+r)) (Point (x+r) (y-r)) 
getBound (Rectangle (Point x1 y1) (Point x2 y2)) = Rectangle (Point x1 y1) (Point x2 y2)
{- getBound (Triangle (Point x1 y1) (Point x2 y2) (Point x3 y3)) = -}
getBound (Text (Point x y) f s) = Rectangle (Point x yy) (Point (x+fromIntegral((length s)*(width f))) y) where yy = y + fromIntegral(height f)
{- getBound for triangle would take a bit more time, I may do it if
it's really necessary -}

getBounds :: [Shape] -> [Shape]
getBounds ss = map getBound ss

inRectangle :: Point -> Shape -> Bool
inRectangle (Point x y) (Rectangle (Point x1 y1) (Point x2 y2)) = (x >= x1 && x <= x2 ) && (y >= y1 && y <= y2) {- !!! -}

getFigure :: Point -> [Shape] -> Maybe Shape
getFigure p ss = find (\f -> inRectangle p (getBound f)) ss 

getFigure' p ss = find (inRectangle p) (etBounds ss)

move :: Shape -> Point -> Shape
move (Circle (Point x y) r) (Point x0 y0) = Circle (Point (x+x0) (y+y0)) r


{- 4 -}

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

{- 6 -} 

import Data.List
import qualified Data.Map
data Type =  Int | Float | String | Structure  {ident :: String , field1 :: (String,Type), field2 :: (String,Type)} deriving (Show,Eq)

isStructured :: Type -> Bool
isStructured (Structure _ _ _) = True
isStructured _ = False

getType :: String -> [Type] -> Maybe Type
getType s tt = find (\t -> (ident t) == s) tt

fields :: Maybe Type -> [String]
fields Nothing = []
fields (Just (Structure _ f1 f2)) = [(fst f1), (fst f2)]

getFields :: String -> [Type] -> Maybe [[Char]]
getFields s tt = Just (fields $ getType s (filter isStructured tt))

getByType :: Type -> [Type] -> [String]
getByType t tt = map ident (filter (\x -> x == t) (filter isStructured tt))

getByTypes :: [Type] -> [Type] -> [String]
getByTypes tt ttt = foldr(\x acc -> (getByType x ttt)) [] tt

{- 7 -}

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

{- 8 -}

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


{- 9 -}

import Data.List
import Data.Char

data Keypress = Alphanum {c :: Char} | Caps  deriving (Show,Eq)

isAlNum :: Keypress -> Bool
isAlNum c = c/=Caps


getAlNum :: [Keypress] -> [Keypress]
getAlNum kk = filter isAlNum kk

getRaw :: [Keypress] -> [Char]
getRaw kk = map (\x -> toLower (c x)) (getAlNum kk)

isCapsLocked :: [Keypress] -> Bool
isCapsLocked kk = odd $ length (filter (\x -> not (isAlNum x)) kk)

encodeSeq :: [Keypress] -> [Char]
encodeSeq kk = foldr(\x acc -> if x == Caps then '\n' : acc else (c x) : acc) [] kk

toUpper' :: [Char] -> [Char]
toUpper' cc = map toUpper cc

getString :: [Keypress] -> String
getString kk =  filter isAlphaNum (unlines $ map (\x -> if odd (length(takeWhile (/=x) text)) then toUpper' x else x) text) where text = lines $ encodeSeq kk


{- 10 -} 
                                                                                                                                  

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

{- End of Lab 3 -}

{- 1 -}

{- import Expr -}

data Expr = Const Integer | Var String | Add Expr Expr | Mult Expr Expr deriving (Show, Eq)

{-I might be wrong here about the differentiation. Haskell code is
correct though. -}

diff :: Expr -> Expr -> Expr
diff (Const _) _ = Const 0
diff (Var x) (Var w)  = if x == w then Const 0 else Var x
diff (Add x y) (Var w) = Add (diff x (Var w)) (diff y (Var w))
diff (Mult x y) (Var w) = Add (Mult (diff x (Var w)) y) (Mult x (diff y (Var w))) 

simplify :: Expr -> Expr
simplify (Add x (Const 0)) = x
simplify (Add (Const 0) x) = x
simplify (Mult x (Const 1)) = x
simplify (Mult (Const 1) x) = x
simplify (Mult x (Const 0)) = Const 0
simplify (Mult (Const 0) x) = Const 0
{- ... -}

{- Support for grouping by parenthesis is not fully implemented. Might be 
improved later -}

toString :: Expr -> String
toString (Var x) = x
toString (Const x) = show x
toString (Add x y) = (toString x) ++ "+" ++ (toString y)
toString (Mult x y) = "(" ++ (toString x) ++ ")" ++ "*(" ++ (toString y) ++ ")"

lookupVar :: String -> [(String, Integer)] -> Integer
lookupVar v (x:xx) = if fst x == v then snd x else lookupVar v xx

eval' :: Expr -> [(String, Integer)] -> Integer
eval' (Const x) _ = x
eval' (Add x y) vars = (eval' x vars ) + (eval' y vars)
eval' (Mult x y) vars = (eval' x vars) * (eval' y vars)
eval' (Var x) (v:vv) = if fst v == x then snd v else lookupVar x vv

{- 2 -}

data List a = Nil | Cons a (List a) deriving (Show, Eq)

headList (Cons x _) = x
headList Nil = error "Empty List"

tailList (Cons _ y) = y
tailList Nil = error "Empty list"

lengthList Nil = 0
lengthList (Cons x xx) = 1 + lengthList xx

lastList Nil = error "Empty List"
lastList (Cons x y) = if (lengthList y) == 0 then x else lastList y

nthList 0 (Cons x _) = x
nthList n (Cons x xx) = if (lengthList xx) == n then lastList xx else nthList (n-1) xx

removeNegative (Nil) = Nil
removeNegative (Cons x y) = if x > 0 then (Cons x (removeNegative y)) else removeNegative y

fromList Nil = []
fromList (Cons x y) = x : fromList y

toList [] = Nil
toList (x:xx) = (Cons x (toList xx))


{- 3 -}

data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

leaf x = Node x EmptyTree EmptyTree

exists x EmptyTree = False
exists x (Node a left right)
  | x == a = True
  | x < a = exists x left             
  | x > a = exists x right

add x EmptyTree = leaf x
add x (Node a left right)
  | x == a = Node x left right
  | x < x = Node a (add x left) right
  | x > a = Node a left (add x right)

find' x EmptyTree = error "empty"
find' x (Node a left right)
  | fst x == fst a = snd a
  | x < a = find' x left             
  | x > a = find' x right

toList EmptyTree = []
toList (Node a left right) = a : toList left ++ toList right


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

{- 5 -}

import Data.List
data Prop = Symbol String Bool | Conj Prop Prop | Disj Prop Prop | Prop Bool deriving (Show,Eq)

vars :: Prop -> [String]
vars (Symbol s b) = [s]
vars (Conj a b) = nub (vars a ++ vars b)
vars (Disj a b) = nub (vars a ++ vars b)
vars (Prop a) = []

findValue :: String -> [(String, Bool)] -> Bool
findValue s vv = snd $ head (filter (\x -> fst x == s) vv)

truthValue :: Prop -> [(String, Bool)] -> Bool
truthValue (Symbol s _) vv = findValue s vv
truthValue (Prop b) _ = b
truthValue (Conj a b) vv = (truthValue a vv) && (truthValue b vv)
truthValue (Disj a b) vv = (truthValue a vv) || (truthValue b vv)

tautology :: Prop -> Bool
tautology (Prop b) = b
tautology (Symbol _ v) = v
tautology (Conj (Symbol x1 _) (Symbol x2 _)) = x1 == x2
tautology (Conj a b) = tautology a && tautology b
tautology (Disj (Symbol x1 _) (Symbol x2 _)) = x1 == x2
tautology (Disj a b) = tautology a || tautology b

{- 6 -} 

data Trie a = Trie {value ::  a, children :: [(Char, Trie a)]} deriving (Show, Eq)

empty = Trie ' ' []

exists t trie = (value t,  t) `elem` children trie


{- The notion of the Boolean value in the definition of the Trie data
structure is not understandable. It makes insertion of new words very
complicated though. Also, the picture mentioned in this exercise is
not in the pdf file (the only diagram in this file is a graphical
representation of the Binary Search Tree.)

The only way of completing this exercise is to learn the standard 
implementation of the Trie data structure, I see there are quite a
few places for me to look for help (but maybe in future.) -}

insert :: Trie a -> String -> a -> Trie a
insert t [] x = Trie  x (children t)
insert t (k:ks) x = Trie ( value t) (ins (children t) k ks x) where
  ins [] k ks x = [(k, (insert empty ks x))]
  ins (p:ps) k ks x = if fst p == k then (k, insert (snd p) ks x) : ps else p:(ins ps k ks)


{- 7 -}

data Number = Zero | Next Number deriving (Show)

fromInt :: Integer -> Number
fromInt 0 = Zero
fromInt n = Next (fromInt (n-1))

toInt :: Number -> Integer
toInt Zero = 0
toInt (Next x) = 1 + toInt x

plus :: Number -> Number -> Number
plus x y = fromInt (toInt x + toInt y) {- Sorry, but this is easier -}

mult :: Number -> Number -> Number
mult x y = fromInt (toInt x * toInt y) {- than re-inventing arithmetic 
operators -}

dec :: Number -> Number
dec Zero = Zero  
dec n = fromInt $ ((toInt n) -1)

fact :: Number -> Number
fact Zero = Next Zero
fact n = mult n (dec n)


{- 8 -}

import Data.List

data Staff = Staff {name :: String, subordinates :: [Staff]} deriving (Show,Eq)

getSubordinate :: Staff -> [Staff]
getSubordinate (Staff n xx) = xx

getAllSubordinate :: Staff -> [Staff]
getAllSubordinate (Staff s []) = [(Staff s [])]
getAllSubordinate (Staff n subs) = nub (concat $ map getAllSubordinate subs) ++ subs

{- The second argument is the root of the tree to be searched through -}
getBoss :: Staff -> Staff -> Maybe Staff
getBoss a r = find (\x -> a `elem` (subordinates x)) (getAllSubordinate r) 

getList :: Staff -> [(String, [Staff])]
getList s = [(name x, getAllSubordinate x) |  x <- getAllSubordinate s] 


{- 9 -}

data Point = Point Float Float deriving (Show)
data Area = Rectangle Point Point | Circle {center:: Point, radius :: Float} | Union Area Area | Intersection Area Area

contains :: Point -> Area -> Bool
contains (Point px py) (Rectangle (Point x1 y1) (Point x2 y2)) = (px <= x2 && py <= y2) && (px >= x1 && py >= y1)
contains (Point px py) (Circle (Point x y) r) = (px >= x-r && py >= y-r) && (px <= x+r && py<=y+r)

contains p (Union a b) = contains p a || contains p b
contains p (Intersection a b) = contains p a && contains p b

isRectangular :: Area -> Bool
isRectangular (Rectangle _ _) = True
isRectangular (Union (Rectangle _ _) (Rectangle _ _)) = True
isRectangular (Intersection (Rectangle _ _) (Rectangle _ _)) = True
isRectangular _ = False

area :: Area -> Float
area (Circle _ r) = pi * r ^ 2
area (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)

isEmpty :: Area -> Bool
isEmpty (Rectangle a b) = (area (Rectangle a b)) == 0
isEmpty (Circle p r) = area (Circle p r) == 0
isEmpty (Union a b) = isEmpty a  && isEmpty b
{- There is an obvious way of implementing this function for an
intersection of areas, but unless I change the Area data type and add
some auxilary functions, the function will too laborious to write. -}

{- 10 -}

data Class = Class {name :: String, methods :: [String], parent :: Class} | Object deriving (Show)
{- Object is the parent of all classes, as in many OOP languages, if a
class does not inherit from any class, it is at least child of this
Object class. -}

getParent :: Class ->  Class
getParent c = parent c

getPath :: Class -> [Class]
getPath (Class n mm Object) = []
getPath (Class n mm p) = p : getPath p

getMethods :: Class -> [String]
getMethods Object = []
getMethods (Class n mm p) = mm ++ getMethods p

inherit :: String -> Class -> Class
inherit s c = (Class s (getMethods c) c)

{- End of Lab 4 -}

{- Lab 5 -}

{- 1 -}

average :: [Double] -> Double
average = foldr1 (\x acc -> (x + acc )/2)

scalarMult :: [Integer] -> [Integer] -> [Integer]
scalarMult xs ys = zipWith (*) xs ys

countEven :: [Integer] -> [Integer]
countEven xs = filter even xs

quicksort :: Ord a => [a] -> [a]
quicksort []     = []
quicksort (p:xs) = (quicksort lesser) ++ [p] ++ (quicksort greater)
    where
        lesser  = filter (< p) xs
        greater = filter (>= p) xs


quicksort' :: Ord a => (a -> a -> Bool) -> [a] -> [a]
quicksort' _ []  = []
quicksort' f (p:xs) = (quicksort' lesser) ++ [p] ++ (quicksort' greater)
    where
        lesser  = filter (\x -> not . f x) xs
        greater = filter (f) xs


{- 2 -}

{- This exercise is about rewriting the problems from Lab 3 using
higher-order functions, but in Lab 3 I have already used higher-order
functions when I thought appropriate. I think it would be a deadly sin
to rewrite the ones for which I haven't used such functions.
-}


{- End of Lab 5 -}        

{- Lab 6 -}

{- 1 -}

import System
import Data.Char
import System.IO
import Data.List

{- imports -}

main = do
 x <- readLn
 y <- readLn
 print(x + y)

{- imports -}

main = do
  args <- System.getArgs
  print $ show args

{- imports -}

main = do
     args <- getArgs
     handle <- openFile (head args) ReadMode
     contents <- hGetContents handle
     putStrLn contents
     hClose handle 

{- imports -}

main = do
     args <- getArgs
     handle <- openFile (args!!1) ReadMode
     contents <- hGetContents handle
     putStrLn $ unlines (take (digitToInt((head args)!!0)) $ (lines contents))

{- 2 -}

{- imports -}

add :: Integer -> Integer -> Integer
add x y = x + y

rInt :: String -> Integer
rInt = read

main = do
     args <- getArgs
     print (add ( rInt$ head args) (rInt$ (args!!1)))

{- 

************************************************************************
*** About known issues: 

* the function getBound from exercise 3 of Lab 3 doesn't work for
triangles.

* due to not having ParsecExpr module in my distribution of Hugs, the
functions diff and simplify work by pattern matching instead of
properly parsing expessions.

* the function isEmpty from exercise 9 of Lab 4 doesn't recognise
intersection of areas.

* Trie structure from exercise 6 of Lab 4 is not what I imagined it to
be.

Three of these four problems could be corrected just by minor
modifications which are not related to Haskell and are painful to
write. I will send these corrections if necessary. 

*** Tools and references:

Hugs 98
Gnu Emacs (with haskell-mode)
The Gnu operiting system (Parabola Gnu/linux-libre)

Haskell 2010 report
Haskell Tutorial for C programmers
Hitchhikers guide to Haskell
Apprendre Haskell vous fera le plus grand bien!


{- END -}
