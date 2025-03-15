---
id: week-5-lecture
aliases: []
tags:
  - patterns
  - architecture
  - lecture
  - academy
---

# Design Patterns

Pattern is a reusable not solution, but a **concept** to a common problem.

Described formally:

- **Problem**, which pattern solves
- **Motivation** for solving problem using pattern
- **Structure** of classes of pattern
- **Example** of realization to better get the idea

## For what?

- Patterns - solutions that are commonly used for long time
- Rather if you won't face with such problems, it is good to know, how to solve them
- Patterns - formal language to describe problems for your colleagues
- Conscious mastering of instrument

### Patterns classification

By the level of abstraction:

- Idioms - low level. Can be used inside specific programming language for some element
- Architecture - high level. Can be used in almost any programming language for the whole application

For class of problem:

- **Generative** - describe how objects are created
- **Structure** - describe the connections between objects and classes
- **Behavioral** - describe effective model of communication and division of the area of responsibility

## Singleton

Solves two problems: guaranties that there is only one instance of class and provides global access with protection
against change to it.
