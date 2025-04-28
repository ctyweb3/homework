#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account
{
private:
    double fee;

public:
    CheckingAccount(double initialBalance, double fee);
    void credit(double) override;
    bool debit(double) override;
};

#endif // CHECKINGACCOUNT_H