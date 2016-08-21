Theorem thm:(P->Q)->(Q->R)->P->R.
Proof.
intros H H' p.
apply H'.
apply H.
assumption.
Qed.