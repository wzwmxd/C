Section a.
Require Import ZArith.
Require Import Arith.
Require Import ZArithRing.
Definition div (n m:nat):Prop:=
exists p:nat,p*n=m.
Definition prime (n:nat):Prop:=
forall p:nat,p<n ->~(div p n).

Lemma div_trans:
forall n m p:nat,div n m->(div n (m*p)).
Proof.
intros.
assert (exists p:nat,p*n=m).
apply H.
elim H0.
intros.
exists (x*p).
rewrite<-H1.
ring.
Qed.

End a.
(**
Theorem infinitePrime:
forall p,prime p->(exists p',p'>p/\prime p').
Proof.
intros.
assert (forall n:nat,n<p->~(div n p)).
apply H.
**)