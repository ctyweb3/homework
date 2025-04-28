#include "Account.h"
#include <iostream>

Account::Account(const std::string &number, double initialBalance)
    : accountNumber(number)
{
    if (initialBalance < 0.0)
    {
        std::cout << "Error: Initial balance cannot be negative. Setting to 0.\n";
        balance = 0.0;
    }
    else
    {
        balance = initialBalance;
    }
}

std::string Account::getAccountNumber() const
{
    return accountNumber;
}

double Account::getBalance() const
{
    return balance;
}

void Account::credit(double amount)
{
    if (amount > 0.0)
    {
        balance += amount;
    }
    else
    {
        std::cout << "Error: Credit amount must be positive.\n";
    }
}

bool Account::debit(double amount)
{
    if (amount <= 0.0)
    {
        std::cout << "Error: Debit amount must be positive.\n";
        return false;
    }

    if (amount > balance)
    {
        std::cout << "Error: Debit amount exceeds balance.\n";
        return false;
    }

    balance -= amount;
    return true;
}