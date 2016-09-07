Variable P Q R T:Prop.
Theorem apply_exam:(Q->R->T)->(P->Q)->P->R->T.
Proof.
  intros H H0 p.
  apply H.
  apply H0.
  assumption.
Qed.

Theorem imp_dist:(P->Q->R)->(P->Q)->(P->R).
  Proof.
  intros H H' p.
  apply H.
  assumption.
  apply H'.
  assumption.
Qed.

Lemma id_P:P->P.
  intros;assumption.

Lemma pierce:((P->Q)->P)->P.
  auto.

Require Import Arith.
Definition f:(nat->bool)->(nat->bool)->nat->bool.
  intros f1 f2.
  assumption.
Defined.
Print f.

Opaque f.

