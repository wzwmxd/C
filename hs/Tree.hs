data LeafInfo=Leaf Int
data NodeInfo=Node Int Tree Tree
data TreeInfo=Tree LeafInfo | NodeInfo 
sum (Leaf n) =n
sum (Node(n,t1,t2)) =n+sum(t1)+sum(t2)
