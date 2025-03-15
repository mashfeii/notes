---
id: week-12-lab
aliases:
  - lagrange-method
tags:
  - lab
  - optimization
---

**1.**
$$f(X) = x_1x_2 + x_2x_3$$

$$
\begin{cases}
g_1(X) = x_1 + x_2 - 4 = 0 \\
g_2(X) = x_2 + x_3 - 4 = 0
\end{cases}
$$

$$L(x, \lambda) = x_1x_2 + x_2x_3 = \lambda_1(x_1 + x_2 - 4) + \lambda_2(x_2 + x_3 - 4) - \text{Lagrangian function}$$

$$\frac{\delta L}{\delta x_1} = x_2 + \lambda_1 = 0,\ \frac{\delta L}{\delta x_2} = x_1+x_3-\lambda_2 = 0,\ \frac{\delta L}{\delta x_3} = x_2 + \lambda_2 = 0$$

$$\text{Nessesary condition}: $$

**4.**

1. Since we have inequality constraints, we need to enter slack variables
2. Construct Lagrangian function based on initial function, slack variables and lambdas
3. Find all partial derivatives

$$f(X) = 2x_1 + 4x_2 - x_1^2 - 2x_2^2$$

$$
\begin{cases}
g_1(X) = x_1 + 2x_2 + s_1^2 - 8 = 0 \\
g_2(X) = 2x_1 - x_2 + s_2^2 = 0 \\
g_3(X) = -x_1 + s_3^2 = 0\\
g_4(X) = -x_2 + s_4^2 = 0
\end{cases}
$$

$$L(X, S, \lambda) = 2x_1 + 4x_2 - x_1^2 - 2x_2^2 = \lambda_1(x_1 + 2x_2 + s_1^2 - 8) + \lambda_2(2x_1 - x_2 + s_2^2) - \lambda_3(-x_1 + s_3^2) - \lambda_4(-x_2 + s_4^2)$$

Taking the partial derivatives of $L$ with respect to $X$, $S$ and $\lambda$ we obtain:
$$\frac{\delta L}{\delta x_1} = $$
$$\dots$$
$$\frac{\delta L}{\delta \lambda_4} = $$
This is a maximization problem, here $\lambda_i \geq 0$


