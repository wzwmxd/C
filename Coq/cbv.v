Require Import ZArith.
Open Scope Z_scope.
Definition Zsqr (z:Z):Z:=z*z.
Definition my_fun (f:Z->Z)(z:Z):Z:=f (f z).
Eval cbv delta [my_fun Zsqr] in (my_fun Zsqr).
Eval cbv delta [my_fun] in (my_fun Zsqr).

Eval cbv beta delta [my_fun Zsqr] in (my_fun Zsqr).
Eval cbv beta delta [my_fun] in (my_fun Zsqr).

Definition h (a b:Z):Z:=let s:=a+b in let d:=a-b in s*s+d*d.

Eval cbv zeta beta delta [h] in (h 1 2).
Eval compute in (h 1 2).
Definition f (x:Z):Z:=let s1:=2*x in let s2:=(s1+3)*x in s2+3.
Eval compute in (f 2).
Eval compute in (f 3).
Eval compute in (f 4).
