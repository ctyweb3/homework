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

    // Getter methods for sender information
    std::string getSenderName() const { return sender.name; }
    std::string getSenderAddress() const { return sender.address; }
    std::string getSenderCity() const { return sender.city; }
    std::string getSenderState() const { return sender.state; }
    std::string getSenderZip() const { return sender.zip; }

    // Getter methods for recipient information
    std::string getRecipientName() const { return recipient.name; }
    std::string getRecipientAddress() const { return recipient.address; }
    std::string getRecipientCity() const { return recipient.city; }
    std::string getRecipientState() const { return recipient.state; }
    std::string getRecipientZip() const { return recipient.zip; }

    // Calculate shipping cost
    virtual double calculateCost() const;
};

#endif // PACKAGE_H