#include "Account.h"
#include <iostream>

Account::Account(double initialBalance)
{
    balance = (initialBalance >= 0.0) ? initialBalance : 0.0;
    if (initialBalance < 0.0)
    {
        std::cout << "Error: Initial balance cannot be negative\n";
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
    std::cout << "Debit amount exceeded balance\n";
    return false;
}

double Account::getBalance() const
{
    return balance;
}