{- ABC081B - Shift only -}

solver :: [Int] -> Int
solver xs =
  if all even xs then
    1 + solver (map half xs)
  else
    0
  where
    half x = x`div` 2

main :: IO ()
main = do
  n <- readLn :: IO Int
  xs <- map read . words <$> getLine
  putStrLn . show $ solver xs
