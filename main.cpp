#include "Integrator.h"
#include "SimpsonRule.h"
#include "TrapezoidRule.h"

#include <cmath>
#include <iostream>
#include <string>

int main(int argc, char *argv[]){
    if(argc < 4) {
        std::cout << "Usage: "<< argv[0] << " <double> <double> <size_t>\n";
        return 1;
    }
    
    double a = std::stod(argv[1]);
    double b = std::stod(argv[2]);
    size_t N = (size_t) std::stoi(argv[3]);
    //for(auto i{0}; i < 1e4; i++){
    SimpsonRule tr (
        [](double x){ return std::exp( - x ); }, // Interchangable function pointer
        std::make_pair(a, b),
        N
    );

    std::cout << "Integration Result: " << tr.integrate()  << '\n';
    //}


    return 0;
}
