#include "Integrator.h"
#include "TrapezoidRule.h"

TrapezoidRule::TrapezoidRule(IntegrableFunction1D const& f, Bounds const& bounds, size_t N)
        : Integrator{f, bounds, N}
{}

void TrapezoidRule::compute_weights_and_nodes(Weights& w, Nodes& x)
{
        size_t N = get_num_intervals();

        auto [a, b] = get_bounds();
        double h = (b - a) / N;

        for(auto i{0u}; i < N; ++i)
        {
                x[i] = a + i * h;
                w[i] = h;
        }
        w[0] = h / 2.0 ;
        w[N - 1] = h / 2.0;
}

