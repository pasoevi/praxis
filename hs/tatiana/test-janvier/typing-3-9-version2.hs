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


