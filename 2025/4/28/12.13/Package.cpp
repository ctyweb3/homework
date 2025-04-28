#include "Package.h"
#include <stdexcept>

Package::Package(const Address &s, const Address &r, double w, double cost)
    : sender(s), recipient(r)
{
    // Validate weight and cost per ounce
    if (w <= 0.0)
    {
        throw std::invalid_argument("Weight must be positive");
    }
    if (cost <= 0.0)
    {
        throw std::invalid_argument("Cost per ounce must be positive");
    }

    weight = w;
    costPerOunce = cost;
}

double Package::calculateCost() const
{
    return weight * costPerOunce;
}