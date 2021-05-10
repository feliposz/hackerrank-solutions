{-# LANGUAGE FlexibleInstances, UndecidableInstances, DuplicateRecordFields #-}

module Main where

import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.List.Split
import Data.Set
import Debug.Trace
import System.Environment
import System.IO
import System.IO.Unsafe

fac n = product [1..n]

fn x = 1 + sum [(x ** n) / (fac n) | n <- [1..9]]

main :: IO()
main = do
    n <- readLn :: IO Int

    forM_ [1..n] $ \n_itr -> do
        x <- readLn :: IO Double
        print (fn x)

