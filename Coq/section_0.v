Require Import ZArith.
Section a.
Variable a b:Z.
Definition binomial z:Z:=a*z+b.
Section trinomial_def.
Variable c:Z.
Definition trinomial z:Z:=(binomial z)*z+c.
End trinomial_def.
End a.