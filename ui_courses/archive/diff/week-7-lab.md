---
id: week-7-lab
aliases: []
tags: []
---

## 575.

$$y'' - 2y' + y = \frac{e^x}{x}$$

$$y'' - 2y' + y = 0; y = e^{\lambda x}$$

$$\lambda^2 - 2\lambda + 1 = 0$$

$$(\lambda - 1)^2 = 0$$

$$\lambda_{12} = 1$$

$$y_0 = c_1e^{1\cdot x} + c_2xe^{1 \cdot x} + c_3x^2e^{1 \cdot x}$$

$$
\begin{cases}
  c_1'e^x + c_2'e^x = 0 \\
  c_1'e^x + c_2'(e^x + xe^x) = \frac{e^x}{x}
\end{cases}
$$

$$c_1'e^x = -c_2'xe^x$$

$$-c_2'xe^x + c_2'e^x + c_2'xe^x = \frac{e^x}{x} | \cdot \frac{x}{e^x}$$

$$-c_2x^2 + c_2'x + c_2'x^2 = 1$$

$$c_2'x = 1$$

$$\int{c_2'dx} = \int \frac{1}{x}dx$$

$$c_2 = \ln{|x|} + c_3$$
