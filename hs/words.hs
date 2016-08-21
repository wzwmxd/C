--file wc.hs
--
main=interact worldCount
    where worldCount input=show(length(words input))++"\n"
