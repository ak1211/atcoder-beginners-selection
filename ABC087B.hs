{- ABC087B - Coins -}
import Control.Monad.State.Strict
import Data.Foldable (forM_)

solver :: Int -> Int -> Int -> Int -> Int
solver a b c x =
  flip execState 0 $ do
    forM_ [0..a] $ \i -> do
      forM_ [0..b] $ \j -> do
        forM_ [0..c] $ \k -> do
          if 500*i + 100*j + 50*k == x then modify' succ else pure ()
    get

main :: IO ()
main = do
  a <- readLn :: IO Int
  b <- readLn :: IO Int
  c <- readLn :: IO Int
  x <- readLn :: IO Int
  putStrLn . show $ solver a b c x
