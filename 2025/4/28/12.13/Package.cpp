#include "Package.h"
#include <stdexcept>

Package::Package(const std::string &sName, const std::string &sAddress, const std::string &sCity,
                 const std::string &sState, const std::string &sZip, const std::string &rName,
                 const std::string &rAddress, const std::string &rCity, const std::string &rState,
                 const std::string &rZip, double w, double cost)
    : senderName(sName), senderAddress(sAddress), senderCity(sCity),
      senderState(sState), senderZip(sZip), recipientName(rName),
      recipientAddress(rAddress), recipientCity(rCity),
      recipientState(rState), recipientZip(rZip)
{
    // Validate weight and cost per ounce
    if (w <= 0.0)
    {
        throw std::invalid_argument("Weight must be a positive value");
    }

    if (cost <= 0.0)
    {
        throw std::invalid_argument("Cost per ounce must be a positive value");
    }

    weight = w;
    costPerOunce = cost;
}

double Package::calculateCost() const
{
    return weight * costPerOunce;
}