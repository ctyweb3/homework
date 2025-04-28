#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"

class TwoDayPackage : public Package
{
private:
    double flatFee; // flat fee for two-day delivery service

public:
    // Constructor
    TwoDayPackage(const Address &s, const Address &r, double w, double cost, double fee);

    // Override calculateCost to add flat fee
    double calculateCost() const override;
};

#endif // TWODAYPACKAGE_H