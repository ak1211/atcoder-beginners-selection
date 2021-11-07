{- ABC083B - Some Sums -}
import           Data.List  (unfoldr)
import           Data.Maybe (Maybe (..))

sum_of_digits :: Int -> Int
sum_of_digits =
  sum . unfoldr f
  where
    f x | x == 0 = Nothing
        | otherwise = Just (x `mod` 10, x `div` 10)

solver :: [Int] -> Int
solver [n, a, b] =
  sum [x | x <- [1..n], let z = sum_of_digits x, a <= z && z <= b]

solver _ = 0

main :: IO ()
main = do
  xs <- map read . words <$> getLine
  putStrLn . show $ solver xs
