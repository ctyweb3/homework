#include "TwoDayPackage.h"
#include <stdexcept>

TwoDayPackage::TwoDayPackage(const std::string &sName, const std::string &sAddress, const std::string &sCity,
                             const std::string &sState, const std::string &sZip, const std::string &rName,
                             const std::string &rAddress, const std::string &rCity, const std::string &rState,
                             const std::string &rZip, double w, double cost, double fee)
    : Package(sName, sAddress, sCity, sState, sZip, rName, rAddress, rCity, rState, rZip, w, cost)
{
    // Validate flat fee
    if (fee < 0.0)
    {
        throw std::invalid_argument("Flat fee must be a non-negative value");
    }

    flatFee = fee;
}

double TwoDayPackage::calculateCost() const
{
    // Call base class calculateCost then add the flat fee
    return Package::calculateCost() + flatFee;
}