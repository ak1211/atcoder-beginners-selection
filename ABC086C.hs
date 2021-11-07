{- ABC086C - Traveling -}
import qualified Data.ByteString.Char8 as B8
import           Data.Maybe            (Maybe (..), fromJust, fromMaybe,
                                        isNothing)

data Coord = MkCoord { cx :: Int, cy:: Int }

distance :: Coord -> Coord -> Int
distance a b = abs (cx a - cx b) + abs (cy a - cy b)

solver :: [(Int, Coord)] -> String
solver = yesOrNo . scanl walk zero
  where
    zero = Just (0, MkCoord 0 0)
    --
    walk Nothing _ = Nothing
    walk (Just previous) current =
      let
        dt = fst current - fst previous
        dist = distance (snd current) (snd previous)
      in
      if dt < dist then Nothing
      else if (dt - dist) `mod` 2 == 0 then (Just current)
      else Nothing
    --
    yesOrNo :: [(Maybe (Int, Coord))] -> String
    yesOrNo xs = if any isNothing xs then "No" else "Yes"

main :: IO ()
main = do
  _ <- readLn :: IO Int
  putStrLn . solver =<< map (fromJust . pack . B8.words) . B8.lines <$> B8.getContents
  where
    pack :: [B8.ByteString] -> Maybe (Int, Coord)
    pack [a,b,c] = do
      (t,_) <- B8.readInt a
      (x,_) <- B8.readInt b
      (y,_) <- B8.readInt c
      pure (t, MkCoord x y)
    pack _ = Nothing
