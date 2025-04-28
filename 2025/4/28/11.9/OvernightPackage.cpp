#include "OvernightPackage.h"
#include <stdexcept>

OvernightPackage::OvernightPackage(const Address &s, const Address &r, double w, double cost, double additionalFee)
    : Package(s, r, w, cost)
{
    if (additionalFee < 0.0)
    {
        throw std::invalid_argument("Additional fee must be non-negative");
    }
    additionalFeePerOunce = additionalFee;
}

double OvernightPackage::calculateCost() const
{
    return weight * (costPerOunce + additionalFeePerOunce);
}