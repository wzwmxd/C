--file wc.hs
--
main=interact worldCount
    where worldCount input=show(length(lines input))++"\n"
