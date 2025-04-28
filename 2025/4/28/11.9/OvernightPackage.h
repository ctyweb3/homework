#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package
{
private:
    double additionalFeePerOunce;

public:
    OvernightPackage(const Address &s, const Address &r, double w, double cost, double additionalFee);
    double calculateCost() const override;
};

#endif