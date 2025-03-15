---
id: week-11-lab
aliases: []
tags: []
---
**1.**
$$p = 0.0005$$
$$\lambda = 5 \text{ for 10 000 symbols}$$
$$\xi - \text{number of misspelled words}$$
$$\xi ~ \text{Poiss(5)}$$
$$P(\xi = k) = \frac{e^{-\lambda}\lambda^k}{k!}$$
$$P(\xi \leq 3) = P(\xi = 0) + P(\xi = 1) + P(\xi = 2) + P(\xi = 3)$$
$$= e^{-5}(\frac{5^0}{0!} + \frac{5^1}{1!} + \frac{5^2}{2!} + \frac{5^3}{3!}) = 0.265$$

**2.**
$$\eta_n - \text{sum of points}$$
$$P(\Big|\frac{\eta_n}{n} - 3.5\Big| > \varepsilon)$$
$$\eta_n = x_1 + \dots + x_n \text{, where each } x_i \text{ - result of i-th experiment}$$
$$Ex_i = \frac{1 + 2 + 3 + 4 + 5 + 6}{6} = 3.5$$
$$E\eta_n = E(x_1 + \dots + x_n) = Ex_1 + \dots + Ex_n = nEx_1 = 3.5$$
$$E(\frac{\eta_n}{n}) = \frac{1}{n}E\eta_n = \frac{3.5 \cdot n}{n} = 3.5$$
$$P(|\zeta - \mu_{\zeta}| > \varepsilon) \leq \frac{\text{Var}\zeta}{\varepsilon^2}$$
$$\text{Var}(x_i) = Ex_i^2 - (Ex_i)^2 = \frac{1 + 4 + 9 + 16 + 25 + 36}{6} = \frac{13}{12} = 2.916$$
$$\text{Var}(\eta_n) = \text{Var}(x_1 + \dots + x_n) = \sum_{i = 1}^n{\text{Var}(x_i)}$$

**3.**
$$\xi_1, \xi_2, \dots, \xi_n, \xi_{n+1}, \xi_i ~ Ber(p), i = 1, n+1, \varepsilon > 0$$
$$P(\xi_i = 0) = 1 - p$$
$$P(\xi_i = 1) = p$$
$$\eta_n = \sum_{i = 1}^n{I_i}$$
$$EI_i = 1 \cdot P(\xi_i=\xi_{i + 1}=1) + 0 \dots = P(\xi_i=\xi_{i+1})=1=P(\xi_i=1)P(\xi_{i+1}=1)=p^2$$
$$E\eta_n=E\sum_{i=1}^n{I_i}=\sum_{i=1}^n{EI_i}=np^2$$
$$VarI_i=EI_i^2-(EI_i)^2=p^2-p^4=p^2(1-p^2)$$
$$E(\frac{\eta_n}{n})=\frac{1}{n}E\eta_n=\frac{1}{n}np^2 = p^2$$
$$Var(\eta_n) = Var(\sum_{i=1}^n{I_i}) = \sum_{i=1}^n{VarI_i}+ 2(n-1)p^3(1-p) = np^2(1-p^2)+2(n-1)p^3(1-p)$$
$$Cov(I_i, I_j)=EI_iI_j-EI_iEI_j=|i - j|=1$$

**5.**

$$\xi - \text{number of "2" or "6" points rolls}$$
$$P(2 \text{ or } 6) = \frac{1}{6}+\frac{1}{6} = \frac{1}{3}$$
$$P ~ Bin(1800, \frac{1}{3})$$
$$P(\xi \geq 620) = P(\xi - 600 \geq 20) = P(\frac{\xi - 600}{20} \geq 1) = P(\zeta \geq 1) = 1 - P(\zeta < 1) = 1 -
0.8413 = 0.1587$$
$$\xi ~ Bin(n, p)$$
$$\zeta \sim \frac{\xi - np}{\sqrt{np(1-p)}} \sim N(0, 1), n \to \infty, n \geq 30$$
$$E(\xi) = np,\ Var(\xi) = npq$$
$$\sigma_{\xi} = \sqrt{Var(\xi)} = 20$$

**6.**

$$\xi_i - \text{ number of attempts on i-th employee}$$
$$\xi_i \sim \text{Geo}(\frac{2}{3})$$
$$S_{n=300} = \sum_{i = 1}^n{\xi_i}$$
$$\frac{S_n - \mu n}{\sigma \sqrt{n}} \sim N(0, 1),\ n \to \infty$$
$$E(\xi_i) = \frac{1}{p} = \frac{3}{2}$$
$$Var(\xi_i) = \frac{q}{p^2} = \frac{1}{3} : \frac{4}{9} = \frac{3}{4}$$
$$\sigma_{\xi_i} = \sqrt{Var(\xi_i)} = \sqrt{\frac{3}{4}}= 0.866$$
$$n\cdot E(\xi_i) = \mu \cdot n = 300 \cdot \frac{3}{2} = 450$$
$$\sigma\sqrt{n} = \sigma_{\xi_i} = 0.866 \cdot \sqrt{300} = 14.999 \approx 15$$
$$P(S_n \geq 470) = P(S_n \cdot 450 \geq 20) = P(\frac{S_n - 450}{15} \geq \frac{20}{15}) = P(\zeta \geq \frac{4}{3}) =
1 - P(\zeta < \frac{4}{3}) = 1 - 0.9082 = 0.0918$$
