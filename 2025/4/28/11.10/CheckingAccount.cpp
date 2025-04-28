#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(double initialBalance, double f)
    : Account(initialBalance)
{
    fee = (f >= 0.0) ? f : 0.0;
}

void CheckingAccount::credit(double amount)
{
    Account::credit(amount);
    Account::debit(fee);
}

bool CheckingAccount::debit(double amount)
{
    if (Account::debit(amount))
    {
        Account::debit(fee);
        return true;
    }
    return false;
}