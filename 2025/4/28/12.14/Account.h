#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account
{
private:
    std::string accountNumber;
    double balance;

public:
    // Constructor
    Account(const std::string &number, double initialBalance);

    // Virtual destructor for polymorphic class
    virtual ~Account() = default;

    // Getter for account balance
    double getBalance() const;

    // Deposit money into account
    virtual void credit(double amount);

    // Withdraw money from account
    virtual bool debit(double amount);

    // Get account number
    std::string getAccountNumber() const;
};

#endif // ACCOUNT_H