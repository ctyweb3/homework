#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
private:
    double transactionFee; // Fee charged per transaction

public:
    // Constructor
    CheckingAccount(const std::string &number, double initialBalance, double fee);

    // Override credit to include transaction fee
    void credit(double amount) override;

    // Override debit to include transaction fee
    bool debit(double amount) override;
};

#endif // CHECKINGACCOUNT_H