primeQwilson::Int->Bool
primeQwilson n=if (foldl (\x y->(x*y) `mod` n) 1 [2..(n-1)]) `mod` n==(n-1) then True else False
fac::Int->Int
fac 0=1
fac n=n*(fac (n-1))
combi::(Int,Int)->Int
combi (n,k)
    |k==0=1
    |k==n=1
    |otherwise=(combi (n-1,k))+(combi (n-1,k-1))

prime::Int->[Int]
prime n
    |n<=1=[]
    |n==2=[2]
    |otherwise=[2]
--    |otherwise=foldl (map (\y->(filter (\x->(if x `mod` y==0 then False else True)))) (prime$floor$sqrt n)) [2..n] 
