#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
protected:
    std::string accountNumber;
    double balance;

public:
    // Constructor
    Account(const std::string &number, double initialBalance);

    // Virtual destructor for polymorphic class
    virtual ~Account() = default;

    // Getter for account balance
    double getBalance() const;

    // Get account number
    std::string getAccountNumber() const;

    // Deposit money into account
    virtual void credit(double amount);

    // Withdraw money from account
    virtual bool debit(double amount);
};

#endif // ACCOUNT_H