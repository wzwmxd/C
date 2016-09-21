Require Arith.
Require Compare_dec.
Inductive maxn(f:nat->nat):nat->nat->Prop:=
  maxnO:(maxn f O (f O))
  |maxnSg:forall n m:nat,(maxn f n m)->
    (ge m (f (S n)))->
    (maxn f (S n) m)
  |maxnS1:forall n m:nat, (maxn f n m)->
    (le m (f (S n)))->
    (maxn f (S n)(f (S n))).

Lemma max_val:forall (f:nat->nat)(n:nat),exists m:nat,maxn f n m.
Proof.


