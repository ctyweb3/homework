#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate; // Interest rate (percentage)

public:
    // Constructor
    SavingsAccount(const std::string &number, double initialBalance, double rate);

    // Calculate interest based on current balance and add to account
    double calculateInterest() const;
};

#endif // SAVINGSACCOUNT_H