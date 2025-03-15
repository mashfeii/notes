**649.**

$$\alpha x + \beta e^x + \gamma xe^x = 0$$
$$x(\alpha + \gamma e^x) + \beta e^x = 0 \rightarrow \beta = 0$$

$$
\beta = -\frac{x(\alpha + \gamma e^x)}{e^x} \\
e^x = -\frac{\alpha}{\gamma} \rightarrow \alpha = \gamma = 0
$$

$$
\begin{cases}
y_1 = 1 \\
y_2 = \cos{x} = \pm1
\end{cases}
\rightarrow
\begin{vmatrix}
1 & \cos{x} \\
2 & -\sin{x}
\end{vmatrix}
\ne 0 \rightarrow
-\sin{x} - 0 \cdot \cos{x} = -\sin{x} \ne 0 \rightarrow x \ne \pi n, n \in \mathbb{R}
$$

**Undefined task.**

$y_1 = 3x$
$y_2 = x - 2$
$y_3 = e^x + 1$

$$
\begin{vmatrix}
3x & x - 2 & e^x + 1 \\
3 & 1 & e^x \\
0 & 0 & e^x
\end{vmatrix}
$$

$e^x(3x - 3x + 6) \ne 0$
$6e^x \ne 0$

$$
\begin{vmatrix}
3x & x - 2 & e^x + 1 & y \\
3 & 1 & e^x & y' \\
0 & 0 & e^x & y'' \\
0 & 0 & e^x & y'''
\end{vmatrix}
$$

$$
-e^x \cdot
\begin{vmatrix}
3x & x - 2 & y \\
3 & 1 & y' \\
0 & 0 & y''
\end{vmatrix}
+ y
\begin{vmatrix}
3x & x - 2 & e^x + 1 \\
3 & 1 & e^x \\
0 & 0 & e^x
\end{vmatrix}
= 0
$$

$$-e^x \cdot y''(3x - 3x + 6) + y''' \cdot e^x \cdot 6 = 0$$
$$-6e^xy'' + 6y'''e^x = 0$$
$$\boxed{y''' - y '' = 0}$$

**513.**

$
\begin{cases}
y' - 2y' = 0 \\
y(0) = 0 \\
y'(0) = 2
\end{cases}
$

$$\sum_{i = 0}^n{a_c \cdot y^{(i)} = 0}$$
$$y(x) = e^{\lambda x}$$

$$(e^{\lambda x})'' - 2(e^{\lambda x})' = 0$$

**Undefined problem**

$$y'' + 4y = 2\tan{x}$$
$$\lambda^2 + 4 = 0$$
$$\lambda^2 = -4$$
$$\lambda_{1|2} = \pm i \cdot 2$$

$$c_1' + c_2'y_2 = 0$$
$$
y = e^{\lambda x}
\begin{cases}
c_1' \cdot e^{2ix} + c_2'e^{-2ix} = 0 \\
2ic_1'e^{2ix} - 2ic_2'e^{-2ix} = 2\tan{x}
\end{cases}
$$
