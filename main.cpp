#include <cmath>
#include <iostream>
#include <string>
#include "TrapezoidRule.h"
#include "Integrator.h"

int main(int argc, char *argv[]){
    if(argc < 4) {
        std::cout << "Usage: "<< argv[0] << " <double> <double> <size_t>\n";
        return 1;
    }
    
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    size_t N = std::stod(argv[3]);

    TrapezoidRule tr (
        [](double x){ return std::exp( - x ); }, // Interchangable function pointer
        std::make_pair(a, b),
        N
    );

    std::cout << "Integration Result: " << tr.integrate()  << '\n';

    return 0;
}
