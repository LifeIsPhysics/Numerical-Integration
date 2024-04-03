#ifndef TRAPEZOID_RULE_H
#define TRAPEZOID_RULE_H

#include "Integrator.h"

class TrapezoidRule : public Integrator
{
public: 
    TrapezoidRule() = delete; 
    TrapezoidRule(IntegrableFunction1D const& f, Bounds const& bounds, size_t N);

    void compute_weights_and_nodes(Weights& w, Nodes& x) override;
};

#endif // TRAPEZOID_RULE_H
