Lemma L_35_36:forall n:nat, 7*5<n->6*6<=n.
Proof.
  intro n.
  intro H.
  assumption.
Qed.
Print L_35_36.

Theorem imp_trans:forall P Q R:Prop,(P->Q)->(Q->R)->P->R.
Proof.
  intros P Q R H H0 p.
  apply H0;apply H;assumption.
Qed.

Print imp_trans.

Check (imp_trans _ _ _(le_S 0 1)(le_S 0 2)).