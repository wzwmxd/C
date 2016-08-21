echo::IO ()
echo=getChar>>=putChar
echoDup::IO ()
echoDup=getChar>>=
    (\c->putChar c >>=
    (\()->putChar c))
echoTwice::IO ()
echoTwice=echo>>echo
getTwoChars::IO (Char,Char)
getTwoChars=getChar>>=
    \c1->getChar>>=
    \c2->return (c1,c2)
