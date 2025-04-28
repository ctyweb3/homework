#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package
{
private:
    double flatFee; // flat fee for two-day delivery service

public:
    // Constructor
    TwoDayPackage(const std::string &sName, const std::string &sAddress, const std::string &sCity,
                  const std::string &sState, const std::string &sZip, const std::string &rName,
                  const std::string &rAddress, const std::string &rCity, const std::string &rState,
                  const std::string &rZip, double w, double cost, double fee);

    // Override calculateCost to add flat fee
    double calculateCost() const override;
};

#endif // TWODAYPACKAGE_H