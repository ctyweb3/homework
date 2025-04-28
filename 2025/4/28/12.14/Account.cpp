#include "Account.h"
#include <iostream>

Account::Account(const std::string &number, double initialBalance)
    : accountNumber(number)
{
    // Validate initial balance
    if (initialBalance < 0.0)
    {
        std::cout << "Error: Initial balance cannot be negative. Setting balance to 0." << std::endl;
        balance = 0.0;
    }
    else
    {
        balance = initialBalance;
    }
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
        std::cout << "Error: Credit amount must be positive." << std::endl;
    }
}

bool Account::debit(double amount)
{
    if (amount <= 0.0)
    {
        std::cout << "Error: Debit amount must be positive." << std::endl;
        return false;
    }

    if (amount > balance)
    {
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return false;
    }

    balance -= amount;
    return true;
}

std::string Account::getAccountNumber() const
{
    return accountNumber;
}