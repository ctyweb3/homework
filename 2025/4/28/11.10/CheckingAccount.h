#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
private:
    double fee;

public:
    CheckingAccount(double initialBalance, double feeAmount);
    void credit(double amount);
    bool debit(double amount);
};

#endif // CHECKING_ACCOUNT_H