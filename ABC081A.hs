{- ABC081A - Placing Marbles -}

solver :: String -> Int
solver =
	foldl (\a c -> if c == '1' then a+1 else a) 0

main :: IO ()
main =
  putStrLn . show . solver =<< getLine
