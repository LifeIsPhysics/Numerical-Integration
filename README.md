# Motivation
Integration is an essential tool in science, engineering and mathematics. In physics for example, 
the volume or area of an object can be determined after modeling the object using multidimensional 
functions and setting the integration bounds. Unfortunately, there sometimes is no analytical 
solution to an integration problem; its functions are called nonelementary integrals, e.g 
$\frac{\sin{x}}{x},\ \exp{-x^2}$. In that case, however we can make use of numerical integration 
which approximates the area underneath a one-dimensional function by calculating 
$\int_a^b f(x) dx = \sum_i^N w_i f(x_i)$, where $w_i$ are weights (determined by the integration 
method) and $x_i$ ($i = 0,..., N-1$) are nodes separated by the integration step size 
$h = \frac{b - a}{N}$. 

