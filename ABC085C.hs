{- ABC085C - Otoshidama -}
import qualified Data.ByteString.Char8 as B8
import           Data.Maybe            (fromMaybe, listToMaybe)

data ABC = ABC Int Int Int
instance Show ABC where
	show (ABC a b c) = show a ++ " " ++ show b ++ " " ++ show c

solver :: Int -> Int -> ABC
solver n y =
  fromMaybe notFound $ listToMaybe
    [ABC a b c | a <- [0..n], b <- [0..(n-a)], let c = n-a-b, cond a b c]
  where
    cond a b c = 10000*a + 5000*b + 1000*c == y
    notFound = ABC (-1) (-1) (-1)

main :: IO ()
main = do
  [n, y] <- map read . words <$> getLine
  putStrLn . show $ solver n y
