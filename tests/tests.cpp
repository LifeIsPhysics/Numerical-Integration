#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "helper.h"
#include "doctest.h"
#include "Integrator.h"
#include "TrapezoidRule.h"
#include "SimpsonRule.h"

#include <vector>
#include <tuple>
#include <cmath>

std::vector<std::tuple<IntegrableFunction1D, Bounds, double>> test_cases
{
        std::make_tuple([](double x){ return std::exp(-x); }, std::make_pair(0.,1.), 1 - 1 / M_E),
        std::make_tuple([](double x){ return std::cos(x) - 3.0 / std::pow(x, 5.0); }, std::make_pair(1.,4.), std::sin(4.0) - std::sin(1.0) - 765.0 / 1024.0),
};


TEST_CASE("Trapezoidal Rule Tests.")
{   
    size_t N = 1e6;

    for( auto const& test_case : test_cases)
    {
        auto [f, bounds, exact] = test_case;
        auto calculated = TrapezoidRule(f, bounds, N).integrate();
        std::cout << calculated << " " << exact << '\n';

        CHECK(equal(calculated, exact, 1e-4, 1e-4));
    }
}

TEST_CASE("Simpson Rule Tests.")
{
    size_t N = 1e6;
    
    for( auto const& test_case : test_cases)
    {
        
        auto [f, bounds, exact] = test_case;
        auto calculated = SimpsonRule(f, bounds, N).integrate();
        std::cout << calculated << " " << exact << '\n';
        
        CHECK(equal(calculated, exact, 1e-4, 1e-4));
    }
}
