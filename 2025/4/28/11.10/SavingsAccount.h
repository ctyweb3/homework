#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate);
    double calculateInterest() const;
};

#endif // SAVINGS_ACCOUNT_H