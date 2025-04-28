#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

struct Address
{
    std::string name;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
};

class Package
{
private:
    Address sender;
    Address recipient;

protected:
    double weight;
    double costPerOunce;

public:
    Package(const Address &s, const Address &r, double w, double cost);
    virtual ~Package() = default;
    virtual double calculateCost() const;
};

#endif // PACKAGE_H