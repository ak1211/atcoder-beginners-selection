{- ABC049C - Daydream -}
import qualified Data.ByteString.Char8 as B8
import           Prelude               hiding (words)

words :: [B8.ByteString]
words = map B8.pack [ "dream", "dreamer", "erase", "eraser" ]

solver :: B8.ByteString -> B8.ByteString
solver s =
  if go 0 then B8.pack "YES" else B8.pack "NO"
  where
    go idx | idx == B8.length s = True
    go idx =
      let
        s' = B8.drop idx s
        cond w = B8.isPrefixOf w s'
        nextIdx w = idx + B8.length w
      in
        any (== True) [if cond w then go (nextIdx w) else False | w <- words]

main :: IO ()
main = B8.putStrLn . solver =<< B8.getLine
