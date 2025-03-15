---
id: week-10-lab
aliases: []
tags: []
---

4.

$$y'' + y = 4e^x$$
$$\lambda = \pm i$$
$$y_0 = c_1\cos{x} + c_2\sin{x}$$
$$y_p = ae^x \rightarrow a = 2$$

$$y(x) = 2\cos{x} - 5 \sin{x} + 2e^x$$
$$y = c_1\cos{x} + c_2\sin{x} + 2e^x$$
$$y' = -c_1\sin{x} + c_2\cos{x} + 2e^x$$

$$
\begin{cases}
4 = c_1 + 2 \\
-3 = c_2 + 2
\end{cases}
$$

5.

$$y'' - y = 2x; y(0) = 0; y(1) = 1$$
$$\lambda^2 - 1 = 0$$
$$\lambda = \pm i$$
$$y = c_1e^x + c_2e^{-x}$$
$$y_p = ax + b \rightarrow a = 2, b = 0$$
$$y = c_1x+c_2^{-x}$$

$$
\begin{cases}
0 = c_1 + c_2 - 0 \\
1 = c_1e + \frac{c_2}{e} - 2
\end{cases}
$$

$$3 = c_1e - \frac{c_1}{e}=c_1(\frac{e^2-1}{e})'$$
$$c_1 = \frac{3e}{e^2-1}$$
$$c_2=\frac{3e}{1 - e^2}$$
$$y = \frac{3e^{x + 1}}{e^2 - 1} + \frac{3e^{-x + 1}}{1 - e^2}$$

3.

$$(y - \frac{1}{x}) + \frac{y'}{y} = 0$$
$$\frac{y'}{y}+y = \frac{1}{x}$$
$$y'-\frac{1}{x}y=-y^2$$
$$y^{-1}e^{\frac{1}{x}dx}=\int{e^{\frac{1}{x}dx}}dx$$
$$\frac{1}{y}=\frac{x}{2}+\frac{c}{x}$$
$$y=\frac{1}{\frac{x}{2} + \frac{c}{x}}$$

Another method for second step:
$$y - \frac{1}{x} + \frac{dy}{dxy} = 0 | \cdot dx$$
$$ydx - \frac{dx}{x} + \frac{dy}{y} = 0$$
$$ydx - d(ln|x| - ln|y|) = 0$$
$$ydx - d(ln\Bigg|\frac{x}{y}\Bigg|) = 0$$

Change of variables:

$$ln\Bigg|\frac{x}{y}\Bigg| = t$$
$$\frac{x}{y} = e^t$$
$$y = \frac{x}{e^t}$$

Substitute back:

$$\frac{xdx}{e^t} = 0$$
$$\int xdy = \int e^tdt$$
$$\frac{x^2}{2} = e^t$$

4.

$$y = y' + 2y'$$
$$p = y'; p' = y''$$
$$y' = p \rightarrow \frac{dy}{dx} = p \rightarrow dy = pdx$$
$$y = d(p^2 + 2p^3)$$
$$pdx = pdp(2p+6p^2)$$
$$1 \cdot dx = dp(2 + 6p)$$
$$x = 2p + 3p^2$$

3.

$$y'' + y = \frac{2}{\cos^3{x}}$$
$$\lambda^2 + 1 = 0$$
$$\lambda = \pm i$$
$$y_0 = c_1\cos{x} + c_2\sin{x}$$

$$
\begin{bmatrix}
\cos{x} & \sin{x} \\
-\sin{x} & \cos{x}
\end{bmatrix}
=
\begin{bmatrix}
0 \\
\frac{2}{\cos^3{x}}
\end{bmatrix}
$$

$$
\begin{cases}
c_1'\cos{x} + c_2'\sin{x} = 0 \\
-c_1'\sin{x} + c_2'\cos{x} = \frac{2}{\cos^3{x}}
\end{cases}
\rightarrow
\frac{c_2'(\sin^2{x} + \cos^2{x})}{\cos{x}} = \frac{2}{\cos^3{x}}
$$

$$
\begin{cases}
c_2' = \frac{2}{\cos^2{x}} \\
c_1' = \frac{\frac{2}{\cos^2{x}}+\sin{x}}{\cos{x}}
\end{cases}

\rightarrow

\begin{cases}
c_2' = \frac{2}{\cos^2{x}} \\
c_1' = \frac{2\sin{x}}{\cos^3{x}}
\end{cases}
$$

$$c_1 = 2\int{\frac{\sin{x}}{\cos^3{x}}dx} = 2 \cdot \frac{\tan^2{x}}{2} = \tan^2{x}$$
$$c_2 = 2 + p(x) + c$$
$$y(x) = (\tan^2{x} + c_1)$$
