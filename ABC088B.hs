{- ABC088B - Card Game for Two -}
import           Data.List  (sortBy, unfoldr)
import           Data.Maybe (Maybe (..))

solver :: [Int] -> Int
solver xs =
  let reversed      = sortBy (\x y -> compare y x) xs
      (alice, bob)  = deal reversed
  in
  sum alice - sum bob
  where
    deal = unzip . unfoldr f
    f []         = Nothing
    f [a]        = Just ((a,0), [])
    f (a:b:rest) = Just ((a,b), rest)

main :: IO ()
main = do
  n <- readLn :: IO Int
  xs <- map read . words <$> getLine
  putStrLn . show $ solver xs
