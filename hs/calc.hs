data Term=
    Lit Int|
    Mul Term Term|
    Div Term Term
evalTerm::Term->Int
evalTerm (Mul e1 e2)=(evalTerm e1)*(evalTerm e2)
evalTerm (Div e1 e2)=(evalTerm e1)/(evalTerm e2)
evalTerm (Lit n)=n
data Expr=
    Exp Term|
    Opp Expr|
    Add Expr Expr|
    Sub Expr Expr
eval (Exp t)=(evalTerm t)
eval (Opp t)=(-(eval t))
eval (Add t1 t2)=(eval t1)+(eval t2)
eval (Sub t1 t2)=(eval t1)-(eval t2)
