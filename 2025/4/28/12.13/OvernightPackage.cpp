#include "OvernightPackage.h"
#include <stdexcept>

OvernightPackage::OvernightPackage(const std::string &sName, const std::string &sAddress, const std::string &sCity,
                                   const std::string &sState, const std::string &sZip, const std::string &rName,
                                   const std::string &rAddress, const std::string &rCity, const std::string &rState,
                                   const std::string &rZip, double w, double cost, double additionalFee)
    : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, cost)
{
    // Validate additional fee per ounce
    if (additionalFee < 0.0)
    {
        throw std::invalid_argument("Additional fee per ounce must be a non-negative value");
    }

    additionalFeePerOunce = additionalFee;
}

double OvernightPackage::calculateCost() const
{
    // For overnight delivery, total cost is (base cost + additional fee) * weight
    return weight * (costPerOunce + additionalFeePerOunce);
}