module Main where

import Data.Char

data Game = Game { id :: Int, picks :: [Pick] } deriving Show
data Pick = Pick { red :: Int, green :: Int, blue :: Int } deriving Show

test :: String
test = "Game 99: 15 red, 7 green, 11 blue; 2 blue, 12 green, 17 red; 6 red, 3 blue, 11 green; 14 red, 13 green, 5 blue"

parse :: String -> Game
parse s = case break (==':') s of
            (g, p:ps) -> Game (parseGame g) (parsePicks ps)

parseGame :: [Char] -> Int
parseGame cs = read (dropWhile (\x -> not (isDigit x)) cs) :: Int

parsePicks :: [Char] -> [Pick]
parsePicks cs = map parsePick (splitOn ';' cs) 

parsePick :: [Char] -> Pick
parsePick cs = foldr parsePick' (Pick 0 0 0) (splitOn ',' cs)


parsePick' :: String -> Pick -> Pick
parsePick' cs pick = case words cs of
                       n:"red":_ -> Pick (read n :: Int) (green pick) (blue pick)
                       n:"green":_ -> Pick (red pick) (read n :: Int) (blue pick)
                       n:"blue":_ -> Pick (red pick) (green pick) (read n :: Int)
                      

-- Why do I have to write this myself?
splitOn :: Char -> [Char] -> [[Char]]
splitOn c [] = []
splitOn c cs = case break (==c) cs of
                 (h, "") -> [h]
                 (h, t:ts) -> [h] ++ (splitOn c ts)

filterGames :: [Game] -> [Game]
filterGames gs = filter (\g -> all pickIsValid (picks g)) gs

pickIsValid :: Pick -> Bool
pickIsValid p = (red p) <= 12 && (green p) <= 13 && (blue p) <= 14

main :: IO ()

main = do 
  lines <- getContents
  let games = map parse (splitOn '\n' lines)
  let fgames = filterGames games
  let total = sum (map Main.id fgames)
  print total
