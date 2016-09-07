Require Import ZArith.
Section realization.
  Variable (A B:Set).
  Let spec:Set :=(((A->B)->B)->B)->A->B.
  Let realization:spec:=fun (f:((A->B)->B)->B) a=>f (fun g=>g a).