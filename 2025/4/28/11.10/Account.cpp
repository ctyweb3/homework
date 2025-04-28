#include "Account.h"
#include <iostream>

Account::Account(double initialBalance)
{
    if (initialBalance >= 0.0)
    {
        balance = initialBalance;
    }
    else
    {
        balance = 0.0;
        std::cout << "Error: Initial balance was invalid. Balance set to 0.0." << std::endl;
    }
}

void Account::credit(double amount)
{
    balance += amount;
}

bool Account::debit(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
        return true;
    }
    else
    {
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return false;
    }
}

double Account::getBalance() const
{
    return balance;
}