Section Minimal_propositional_logic.
  Variable P Q R T:Prop.
  Theorem imp_trans:(P->Q)->(Q->R)->P->R.
  Proof.
  intros H H' p.
  apply H'.
  apply H.
  assumption.
  Qed.
  Print imp_trans.
  Theorem imp_trans1:(P->Q)->(Q->R)->P->R.
  Proof.
  auto.
  Qed.