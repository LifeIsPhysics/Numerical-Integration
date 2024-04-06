#include "Integrator.h"
#include "SimpsonRule.h"

SimpsonRule::SimpsonRule(IntegrableFunction1D const& f, Bounds const& bounds, size_t N)
        : Integrator{f, bounds, N} {}

void SimpsonRule::compute_weights_and_nodes(Weights& w, Nodes& x)
{
        size_t N = get_num_intervals();
        auto [a, b] = get_bounds();
        double h = (b - a) / (double) N;

        for(auto i{ 0u }; i < N; ++i){
                x[i] = a + i * h;
                w[i] = 2.0 * h / 3.0;

                if(i % 2 != 0) w[i] = 4.0 * h / 3.0;
        }

        w[0] = h / 3;
        w[N - 1] = h / 3;
}

