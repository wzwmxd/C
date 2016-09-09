Section cut.
  Variable P Q R T:Prop.
  Hypotheses  (H:P->Q)
              (H0:Q->R)
              (H1:(P->R)->T->Q)
              (H2:(P->R)->T).
  Theorem cut:Q.
  Proof.
    cut (P->R).
    intro H3.
    apply H1;[assumption|apply H2;assumption].
    intro;apply H0;apply H;assumption.
  Qed.
  Print cut.
  Theorem cut1:Q.
  Proof.
    auto.
  Qed.
  Theorem auto1:((P->Q->P)->(Q->R)->((((P->Q)->Q)->P)->Q)->R)->R.
  Proof.
    auto 6.
 Qed.
End cut.
Print cut.
