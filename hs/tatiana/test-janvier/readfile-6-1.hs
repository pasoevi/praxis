
import System
import Data.Char
import System.IO
import Data.List

main = do
     args <- getArgs
     handle <- openFile (head args) ReadMode
     contents <- hGetContents handle
     putStrLn contents
     hClose handle 
