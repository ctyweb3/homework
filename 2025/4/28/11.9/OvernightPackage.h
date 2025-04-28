#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"

class OvernightPackage : public Package
{
private:
    double additionalFeePerOunce; // additional fee per ounce for overnight delivery

public:
    // Constructor
    OvernightPackage(const std::string &sName, const std::string &sAddress, const std::string &sCity,
                     const std::string &sState, const std::string &sZip, const std::string &rName,
                     const std::string &rAddress, const std::string &rCity, const std::string &rState,
                     const std::string &rZip, double w, double cost, double additionalFee);

    // Override calculateCost to add additional fee per ounce
    double calculateCost() const override;
};

#endif // OVERNIGHTPACKAGE_H