data BookInfo=Book Int String [String] deriving (Show)
data MagazineInfo=Magazine Int String [String] deriving (Show)
type CustomerID=Int
type ReviewBody=String
data BookReview=BookReview BookInfo CustomerID ReviewBody
myInfo = Book 9780135072455 "Algebra of Programming" ["Richard Bird", "Oege de Moor"]
