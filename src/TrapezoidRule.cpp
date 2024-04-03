#include "TrapezoidRule.h"
#include "Integrator.h"

TrapezoidRule::TrapezoidRule(IntegrableFunction1D const& f, Bounds const& bounds, size_t N)
        : Integrator(f, bounds, N)
{}

void TrapezoidRule::compute_weights_and_nodes(Weights& w, Nodes& x)
{
        auto N = get_num_intervals();

        auto [a, b] = get_bounds();
        auto h = (b - a) / N;

        for(auto i{0u}; i < N; ++i)
        {
                x.push_back(a + i * h);
                w.push_back(h);
        }
        w[0] /= 2;
        w[N - 1] /= 2;
}

