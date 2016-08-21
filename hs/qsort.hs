qsort::(Ord a)=>[a]->[a]
qsort []=[]
qsort (x:xs)=qsort [y|y<-xs,y<x]++[x]++(qsort [y|y<-xs,y>=x])

qsortf::(a->a->Bool)->[a]->[a]
qsortf cmp []=[]
qsortf cmp (x:xs)=qsortf cmp (filter (cmp x) xs)++[x]++qsortf cmp (filter (not.cmp x) xs)
