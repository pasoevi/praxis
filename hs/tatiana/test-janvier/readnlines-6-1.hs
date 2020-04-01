
import System
import Data.Char
import System.IO
import Data.List

main = do
     args <- getArgs
     handle <- openFile (args!!1) ReadMode
     contents <- hGetContents handle
     putStrLn $ unlines (take (digitToInt((head args)!!0)) $ (lines contents))
