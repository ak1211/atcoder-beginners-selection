{- ABC086A - Product -}

solver :: [Int] -> String
solver xs = case xs of
  [a, b]  | even (a*b) -> "Even"
          | otherwise ->  "Odd"
  _ -> "?"

main :: IO ()
main =
  putStrLn . solver =<< input
  where
    input = map read . words <$> getLine
