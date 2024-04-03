#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <vector>
#include <functional>

using IntegrableFunction1D = std::function<double(double)>;
using Bounds = std::pair<double, double>;
using Weights = std::vector<double>;
using Nodes = std::vector<double>;


class Integrator
{
private:
    IntegrableFunction1D const& m_f;
    Bounds const& m_bounds;
    size_t m_num_intervals;

public:
    Integrator() = delete;
    Integrator(IntegrableFunction1D const& f, Bounds const& bounds, size_t N);
    ~Integrator() = default;

    Bounds const get_bounds() const;
    size_t const get_num_intervals() const;
    virtual void compute_weights_and_nodes(Weights& w, Nodes& x){};

    double const integrate();
};

#endif // INTEGRATOR_H
