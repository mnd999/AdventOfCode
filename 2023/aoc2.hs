module Main where

import Data.Char

data Game = Game { id :: Int, picks :: [Pick] }
data Pick = Pick { red :: Int, green :: Int, blue :: Int }

instance Read Game where
  readsPrec _ ('G':'a':'m':'e':' ':n:':':therest) = 
		[(Game (digitToInt n) [], therest)]

instance Read Pick where
	readsPrec _ input = [(Pick 1 2 3, "")]
				
instance Show Game where
	show (Game id picks) = show id

readGame :: IO Game
readGame = readLn

main :: IO ()

main = readGame map show

