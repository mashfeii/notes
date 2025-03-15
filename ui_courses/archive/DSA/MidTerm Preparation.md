# Midterm Preparation

## Asymptotic Notations

Find: $c, n_0$ such that for $\forall n \geq n_0$ inequality holds

$f(n) = O(g(n))$
Prove: $f(n) \leq c \times g(n)$

$f(n) = o(g(n))$
Prove: $f(n) < c \times g(n)$

$f(n) = \Omega (g(n)$
Prove: $f(n) \geq c \times g(n)$

$f(n) = \omega g(n)$
Prove: $f(n) < c \times g(n)$

$f(n) = \Theta g(n)$
Prove: $c_1 \times g(n) \leq f(n) \leq c_2 \times g(n)$

## Tasks

1.$n^2 + n = O(n^3)$
  Let's take $c = 2, n_0 = 1$:
  -$1 + 1 \leq 2 \times 1$
  -$4 + 2 \leq 2 \times 8$
  -Since that, $n^3$ is the upper bound for $f(n) = n^2 + n$

2. Fill the table:
  | A | B | $A = O(B)$ | $A = o(B)$ | $A = \Omega (B)$ | $A = \omega (B)$ | $A = \Theta (B)$ |
  | --- | --- | --- | --- | --- | --- | --- |
  | $\log^5{n}$ | $\sqrt[4]{n}$ | Yes | Yes | No | No | No |
