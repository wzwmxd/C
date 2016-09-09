Require Import Arith.
Open Scope nat_scope.
Check fst.
Section conv.
  Theorem conv_ex:forall n:nat,7*5<n->6*6<=n.
  Proof.
    intros.
    assumption.
  Qed.
  Theorem imp_trans:forall P Q R:Prop,(P->Q)->(Q->R)->P->R.
  Proof.
    intros P Q R H H0 p.
    apply H0;apply H;assumption.
  Qed.
  Print imp_trans.

