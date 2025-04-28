#include "TwoDayPackage.h"
#include <stdexcept>

TwoDayPackage::TwoDayPackage(const Address &s, const Address &r, double w, double cost, double fee)
    : Package(s, r, w, cost)
{
    // Validate flat fee
    if (fee < 0.0)
    {
        throw std::invalid_argument("Flat fee must be non-negative");
    }
    flatFee = fee;
}

double TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + flatFee;
}