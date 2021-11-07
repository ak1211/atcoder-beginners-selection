{- ABC085B - Kagami Mochi -}
import           Control.Monad (replicateM)
import           Data.List     (nub)

solver :: [Int] -> Int
solver = length . nub

main :: IO ()
main = do
  n <- readLn :: IO Int
  xs <- replicateM n readLn
  putStrLn . show $ solver xs
