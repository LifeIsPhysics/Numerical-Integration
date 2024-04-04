#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "helper.h"
#include "doctest.h"
#include "Integrator.h"
#include "TrapezoidRule.h"

#include <vector>
#include <tuple>
#include <cmath>

std::vector<std::tuple<IntegrableFunction1D, Bounds, size_t, double>> test_cases
{
        std::make_tuple([](double x){ return std::exp(-x); }, std::make_pair(0.,1.), 1e6, 1 - 1 / M_E),
        std::make_tuple([](double x){ return std::cos(x) - 3.0 / std::pow(x, 5.0); }, std::make_pair(1.,4.), 1e6, std::sin(4.0) - std::sin(1.0) - 765.0 / 1024.0),
};


TEST_CASE("Trapezoidal Rule Tests.")
{
    for( auto const& test_case : test_cases)
    {
        auto& [f, bounds, N, exact] = test_case;
        auto calculated = TrapezoidRule(f, bounds, N).integrate();
        
        CHECK(equal(calculated, exact));
    }
}
