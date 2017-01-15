import Data.List
import qualified Data.Map
{-data Primitive = Int | Float | String-}
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