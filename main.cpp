#include <cmath>
#include <iostream>
#include "TrapezoidRule.h"
#include "Integrator.h"

int main(){
    TrapezoidRule tr (
        [](double x){ return std::exp( - x ); },
        std::make_pair(0.0, 1.0),
        5000u
    );

    std::cout << "Result: " << tr.integrate()  << '\n';

    return 0;
}
