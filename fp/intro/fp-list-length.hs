len :: [a] -> Int
len lst = case lst of 
    [] -> 0
    (x:xs) -> 1 + len xs
