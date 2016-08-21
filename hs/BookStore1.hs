type CardHolder=String
type CardNumber=String
type Address=[String]

data BilingInfo =CreditCard CardNumber CardHolder Address deriving (Show)
