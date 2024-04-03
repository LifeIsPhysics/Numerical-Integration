#include "Integrator.h"

Integrator::Integrator(IntegrableFunction1D const& f, Bounds const& bounds, size_t N)
        : m_f{ f }, m_bounds{ bounds }, m_num_intervals{ N } {}

double const Integrator::integrate()
{
        Weights w(m_num_intervals);
        Nodes   x(m_num_intervals);

        compute_weights_and_nodes(w, x);

        double res{0.0};
        for(auto i{ 0u }; i < m_num_intervals; ++i){
                res += w[i] * m_f(x[i]);
        }

        return res;
}

Bounds const Integrator::get_bounds() const
{
    return m_bounds;
}

size_t const Integrator::get_num_intervals() const
{
    return m_num_intervals;
}
