# Lecture 7. Midterm Recap

> [!NOTE]
> Regular languages are languages which can be recognized by an automaton with **fixed memory** 
> Fixed memory (bounded) is more resrictive than infinite (unbounded)
> Finite (bounded) vs. unlimited (unbounded)
> Think about FSA (states only) and PDA (stack can grow)

FSA is a model om computation with **fixed memory** 
PDA has **finite** but not fixed memory 
It is using an **unbounded** amount of memory

Many languages cannot be recognized using only fixed memory 
- For example $a^nb^n$
- FSA cannot count an unlimited $n$
- Number os states is fixed, stack can grow with no bound 

## PDA and compilers

- PDA are **at the heart of compilers** 
- Stack memory has a LIFO policy
- LIFO is suitable to analyze **nested syntatic structures** 
  Arithemtical expressions
  Begin/End
  Activation records
  Parenthesized strings

### PD Transducer

Formally, $<Q, I, \Gamma, \delta, q_0, Z_0, F, O, \Eta>$
  $Q$ is a finites set of states
  $F \isin Q$ is the set of final states
  $O$ is the *output alphabet* 
  $\Eta: Q \times (I \sub \{\epsilon}\times\Gamma \to O^*)

## Operations on PDA

- **Clusore properties** of languages accepted by *deterministic* PDA (by
final state) are different than those of languages accepted by
*nondeterministic* PDA 
- Deterministic PDA are closed under complementation
  The class of deterministic context-free languages is closed under complement 
  The class of non-deterministic context free languages is not closed
under complement 
- Deterministic PDA are not closed under union 

### Loops elimination

- Loops elimintation is essential, otherwise the end of the string may never
be reached
- What if there are sequences of $\epsilon$-moves traversing some final and
  some non-final states (and the input is entirely read)?
- With these pecautions, we are sure that either the PDA or its complement
will accept the string 

## Automata Theory and Models of Computation 

Different Models of computation:

- Sequential
  Finite state Automata
  Pushdown Automata
  Turing Machine
- Functional
  Lambda calculus
- Concurrent
  Petri nets 

> Finite State Automata can be used for analysis and design of systems

## Tutorial Week 7.

` < input str > , < stack > , < output str >`
` < input str > , < stack > : < output str >`

> [!NOTE] Pushdown Transducer
> tuple $<Q, \sum, \Gamma, \delta, q_0, Z_0, F, O, \Eta>$
> $Q$ is a finite set of states 
> $\sum$ and $\Gamma$ are finites sets, the input and stack alphabets 
> $\delta$, the transition function, is a prtial function from $Q \times
> (\sum \sub \{\epsilon\}) \times \Gamma$ to the set of finite subsets of $Q
> \times \Gamma^*$
> $q_o \in Q$, the initial state
> $Z_0 \in \Gamma$, the initial stack symbol
> $F \belong Q$, the set of accepting states 
> $O$ is the output alphabet 
> $\Eta: Q \times (\sum \sub \{\epsilon\}) \times \Gamma \to O^*$

