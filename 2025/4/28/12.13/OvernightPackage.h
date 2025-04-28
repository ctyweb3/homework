#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package
{
private:
    double additionalFeePerOunce; // additional fee per ounce for overnight delivery

public:
    // Constructor
    OvernightPackage(const Address &s, const Address &r, double w, double cost, double additionalFee);

    // Override calculateCost to add additional fee per ounce
    double calculateCost() const override;
};

#endif // OVERNIGHTPACKAGE_H