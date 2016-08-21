main=do 
    line<-getLine
    let line'=reverse line
    putStrLn $ "You said"++line'++" backwarks!"
    putStrLn $ "yes, you really said"++line'++" backwards!"
