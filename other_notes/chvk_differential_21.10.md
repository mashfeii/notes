---
id: chvk_differential_21.10
aliases: []
tags:
  - differential_equations
  - maxim
---

## Lab 6.

**1. (Filippov 641)**

Linear independency:

$$a\overline v_1 + b\overline v_2 = 0$$
$$ay_1 + by_2 = 0$$

$$a(x + 2) + b(x - 2) = 0$$
$$x(a + b) + 2(a - b) = 0$$

$$
\begin{cases}
a + b = 0 \\
a - b < 0 \\
\end{cases}

\rightarrow

\begin{cases}
a = 0 \\
b = 0
\end{cases}
$$

**3. (Filippov 649)**

$$ax + be^x + ce^xx = 0$$

$$
\begin{array}{l}
    x = 0 \\
    x = 1 \\
    x = -1
\end{array}
\begin{cases}
    b = 0 \\
    a + be + ce = 0 \\
-a - c \cdot \frac{1}{e} = 0
\end{cases}

\rightarrow

\begin{cases}
b = 0 \\
c(e - \frac{1}{e}) = 0 \rightarrow c = 0 \\
a = -ce \rightarrow a = 0
\end{cases}
$$

Homogeneous equation

$$f(x)y'' + g(x)y' + h(x)y = 0$$
$$y = c_1y_1 + c_2y_2 + c_3y_3 \leftarrow y_1,y_2,y_3 - \text{linear independent solutions}$$

**6. (Filippov 678)**

$e^x, \sinh{x}, \cosh{x}$
$
\begin{array}{l}
\cosh = \frac{e^x + e^{-x}}{2} \\
\sinh = \frac{e^x - e^{-x}}{2}
\end{array}
\ \ \ \ 
\begin{array}{l}
\cosh' = \sinh \\
\sinh' = \cosh
\end{array}
$

$W = \begin{vmatrix}
f_1 & f_2 & f_3 \\
f_1' & f_2' & f_3' \\
f_1'' & f_2'' & f_3'' \\
\end{vmatrix} = 
\begin{vmatrix}
e^x & \sinh x & \cosh x \\
e^x & \cosh x & \sinh x \\
e^x & \sinh{x} & \cosh x \\
\end{vmatrix}$
$= e^x(\cosh{x}^2 - \sinh{x}\cosh{x}) - e^x(\cosh{x}-\sinh{x}\cosh{x}) - e^x(\sinh{x}^2-\cosh{x}^2)  = -e^x - e^x = 0$
$W \neq 0 \rightarrow f_1, \dots, f_n \text{ are linearly independent}$

$$ae^x + be^x - be^{-x} + ce^x + ce^{-x} = 0$$

$$
\begin{cases}
-b + c = 0 \\
a + b + c = 0
\end{cases}
$$

$$
\begin{cases}
b = 1 \\
c = 1 \\
a = -2
\end{cases}
$$

**7. (Filippov 511)**

$$y'' + y' - 2y = 0$$
$$\lambda^2 + \lambda - 2 = 0$$

$$
\Bigg[
\begin{array}{l}
\lambda = 1 \\
\lambda = -2
\end{array}
$$

**10. (Filippov 519)**

Euler formula: $e^{bi} = \cos{b} + i\sin{b}$

$$y^{(4)} - y = 0$$
$$\lambda^4 - 1 = 0$$
$$\lambda \in \{\pm1; \pm i\}$$
$$y = c_1e^x+c_2e^{-x}+c_3e^{ix}+c_4e^{ix}$$

**12. (Filippov 580)**

$$y'' + y = \frac{2}{\cos{x}^2}$$

Solve homogeneous:

$$y'' + y = 0$$
$$\lambda + 1 = 0$$
$$\lambda = \pm i$$
$$y_0 = c_1e^{-ix}+c_2e^{ex} = c_1\cos{x}+\frac{1}{2}c\sin{x}$$

$$c_1=c_1|x|,c_2=c_2(x) - \text{vary the parameters}$$

$$
\text{Shortcut: } W
\begin{bmatrix}c_1'\\c_2'\end{bmatrix}=
\begin{bmatrix}0\\\frac{2}{\cos{x}^3}\end{bmatrix}
\ \ \ \
\begin{cases}c_1'\cos{x}+c_2'\sin{x}=0\\
-c_1'\sin{x}+c_2'\cos{x}=\frac{2}{\cos{x}^3}\end{cases}
$$

$$
\begin{cases}
c_1' = -c_2'\tan{x}\\
c_2'(\tan{x}\sin{x} + \cos{x}) = \frac{2}{\cos{x}^3}
\end{cases}
\ \ \ \
\begin{cases}
c_2' \cdot \frac{1}{\cos{x}^2}=\frac{2}{\cos{x}^4}, c_2' = \frac{2}{\cos{x}^2} \\
c_1' = -2\tan{x} \cdot \frac{1}{\cos{x}^2}
\end{cases}
\ \ \ \
\begin{cases}
c_2 = 2\tan{x}+\hat{c_2}
\end{cases}
$$

$$
\begin{bmatrix}
\cos{x} & \sin{x} \\
-\sin{x} & \cos{x}
\end{bmatrix}
$$

## Lab 7

$$y'' - 2y' + y = 0$$
$$(\lambda - 1)^2 = \lambda^2 - 2\lambda + 1 = 0$$
$$\lambda = 1 - \text{ multiplicity of 2}$$
$$y_0 = c_1e^x + c_2xe^x$$

Patterns (left - pattern, right - solution):

$c_0e^{2x} \mapsto c_1x^5e^{2x}, s = \text{ multiplicity of } \alpha \text{ in char. eq. (0 if not a root)}$

$Q_m(x)e^{2x} \mapsto P_m(x)x^se^{\alpha x}, s = \text{ }$

$e^{\alpha x}(R_{m_1}(x)\cos{\beta x}+T_{m_2}(x)\sin{\beta x}) \mapsto$
$x^se^{2x}(P_m(x)\cos{\beta x}+Q_m\sin{\beta x}),
m = max(m_1, m_2), s = \text{ mul. of } \alpha+\beta i \text{ in char. eq.}$

**1. (Filippov 533)**

$y'' - 2y' - 3y = e^{4x}$

1.  $\lambda^2 - 2\lambda - 3 = 0$
    $\Bigg[ \begin{array}{l}\lambda = -1\\\lambda = 3\end{array}$
    $y_0 = c_1e^{-x}+c_2e^{3x}$
2.  $RHS = e^{4x} \rightarrow \lambda = 4 - \text{not a solution, s = 0}$
    $y_1 = c_3e^{4x}$
3.  $c_316e^{4x} - c_3\cdot8e^{4x}-c_3\cdot e^{4x} = e^{4x}$
    $c_3 \cdot 5 = 1, c_3 = \frac{1}{5}$
    $y_1 = \frac{e^{4x}}{5}$
4.  $y = c_1e^{-x}+c_2e^{3x}+\frac{e^{4x}}{5}$

**3. (Filippov 546)**

1.  $y'' + y = x\sin{x}$
    $\lambda^2 + 1 = 0$
    $\lambda = \pm i$

    $y_0 = c_1e^{-ix}+c_2e^{ix} =c_1\cos{x}+c_2\sin{x}$ 2. second 3. third

2.  $RHS = x\sin{x} = e^{0x}(0\cos{1x}+x\sin{1x}) \rightarrow \lambda = 0, \beta = 1, m_1 = 0, m_2 = 1 \rightarrow m = 1,
   \alpha + \beta = i$
    $\alpha + \beta i - \text{ root of mult.} \rightarrow s = 1$
    $y_1 = x(P_1(x)\cos{x}+Q_1(x)\sin{x}) = x((c_3 + c_4x)\cos{x} + (c_5+c_6x)\sin{x}) =
(c_3x+c_4x^2)\cos{x}+(c_5+c_6x^2)\sin{x}$
    $y_1 = A\cos{x} + B\sin{x}$
    $y_1' = (A'+B)\cos{x}+(B'-A)\sin{x}$
    $y_1'' = (A'' + B' + B' -A)\cos{x} + (B'' - A' - A' - B)\sin{x}$
    $y_1'' + y_1 = (A'' + 2B')\cos{x} + (B'' - 2A')\sin{x} = x\sin{x}$
    $\begin{cases}
        A'' + 2B' = 0 \\
        B'' - 2A' = x 
    \end{cases}
    \rightarrow
    \begin{cases}
        2c_4+2c_5+4c_6x=0\\
        2c_6-2c_3-4c_4x = x
    \end{cases}
    \rightarrow
    \begin{cases}
        4c_6 = 0\\
        c_4+c_5 = 0\\
        -4c_4 = 1\\
        c_6-c_3 = 0
    \end{cases}
    \rightarrow
    \begin{cases}
        c_6 = 0\\
        c_3 = 0\\
        c_4 = -\frac{1}{4}\\
        c_5 = \frac{1}{5}
    \end{cases}$
    $y_1 = -\frac{1}{4}x^2\cos{x} + \frac{1}{4}x\sin{x}$
    $y = y_0 + y_1$
