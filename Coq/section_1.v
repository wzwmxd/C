Reset binomial_def.
Require Import ZArith.
Open Scope Z_scope.
Section binomial_def.
  Variable a b:Z.
  Definition binomial (z:Z):=a*z+b.
  Print binomial.
  Section trinomial_def.
    Variable c:Z.
    Definition trinomial (z:Z):=(binomial z)*z+c.
    Print trinomial.
  End trinomial_def.
  Print trinomial.
End binomial_def.
  Print trinomial.
  Print binomial.