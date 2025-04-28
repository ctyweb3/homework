#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(double initialBalance, double feeAmount)
    : Account(initialBalance)
{
    fee = feeAmount;
}

void CheckingAccount::credit(double amount)
{
    Account::credit(amount - fee);
}

bool CheckingAccount::debit(double amount)
{
    bool success = Account::debit(amount);

    if (success)
    {
        Account::debit(fee);
    }

    return success;
}