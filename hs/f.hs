fib=0:1zipWith (+) fib (tail fib)
main=do
putStrLn $ show $ last $ take 100000 fib
