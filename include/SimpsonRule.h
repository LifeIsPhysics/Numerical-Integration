#ifndef SIMPSON_RULE_H
#define SIMPSON_RULE_H

#include "Integrator.h"


class SimpsonRule : public Integrator
{
public:
    SimpsonRule() = delete; 
    SimpsonRule(IntegrableFunction1D const& f, Bounds const& bounds, size_t N);

    void compute_weights_and_nodes(Weights& w, Nodes& x) override;
};

#endif // SIMPSON_RULE_H
