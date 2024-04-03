#ifndef HELPER_H
#define HELPER_H

#include <cmath>

constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
	return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
constexpr bool equal(double a, double b, double absEpsilon = 1e-4, double relEpsilon = 1e-4)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (std::abs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

#endif // HELPER_H
