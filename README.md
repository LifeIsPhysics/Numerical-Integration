# Motivation
Integration is an essential tool in science, engineering and mathematics. In physics for example, 
the volume or area of an object can be determined after modeling the object using multidimensional 
functions and setting the integration bounds. Unfortunately, there sometimes is no analytical 
solution to an integration problem; its functions are called nonelementary integrals, e.g 
$\frac{\sin{x}}{x},\ \exp(-x^2)$. In that case, however we can make use of numerical integration 
which approximates the area underneath a one-dimensional function by calculating 
$\int{}_a^b f(x) dx = \sum{}_i^N w_i f(x_i)$, where $w_i$ are weights (determined by the integration 
method) and $x_i$ ($i = 0,..., N-1$) are nodes separated by the integration step size 
$h = \frac{b - a}{N}$.  

In this library, the trapezoidal rule is implemented where the weights are implemented as follows: 
$w = {\frac{h}{2}, h, h, ...,\frac{h}{2}}$. You can however create a class which inherits from 
`class Integrator` to implement your own Integrator, which computes its own weights and nodes by 
overriding the the virtual function `void compute_weights_and_nodes(Weights&, Nodes&)`; 
noteable examples include the Simpson's rule or gauss integration.

# Usage

You only need a recent `GCC` compiler capable of `C++23` and `CMake`. On Arch Linux (x86_64), both 
dependencies can be installed using the commands
```bash
sudo pacman -S gcc cmake
```
Clone the repo with these commands
```bash
git clone https://github.com/LifeIsPhysics/Numerical-Integration.git # HTTP
git clone git@github.com:LifeIsPhysics/Numerical-Integration.git     # SSH
```
You can then build the programm with these commands
```bash
cd Numerical-Integration
mkdir build && cd build
cmake ..
make
```
The program can then be run using these commands
```bash
./NumericalIntegrator <double> <double> <size_t>
```

# Example Output
```bash
./NumericalIntegrator 0 1 5000
Integration Result: 0.632047
```
