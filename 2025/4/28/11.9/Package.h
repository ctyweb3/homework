#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

class Package
{
private:
    // Sender information
    std::string senderName;
    std::string senderAddress;
    std::string senderCity;
    std::string senderState;
    std::string senderZip;

    // Recipient information
    std::string recipientName;
    std::string recipientAddress;
    std::string recipientCity;
    std::string recipientState;
    std::string recipientZip;

protected:
    // Package details (protected to allow derived classes to access)
    double weight; // in ounces
    double costPerOunce;

public:
    // Constructor
    Package(const std::string &sName, const std::string &sAddress, const std::string &sCity,
            const std::string &sState, const std::string &sZip, const std::string &rName,
            const std::string &rAddress, const std::string &rCity, const std::string &rState,
            const std::string &rZip, double w, double cost);

    // Calculate shipping cost
    virtual double calculateCost() const;
};

#endif // PACKAGE_H