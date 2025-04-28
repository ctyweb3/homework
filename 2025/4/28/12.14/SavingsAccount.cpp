#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(const std::string &number, double initialBalance, double rate)
    : Account(number, initialBalance)
{
    if (rate < 0.0)
    {
        std::cout << "Error: Interest rate cannot be negative. Setting to 0.\n";
        interestRate = 0.0;
    }
    else
    {
        interestRate = rate;
    }
}

double SavingsAccount::calculateInterest() const
{
    return balance * interestRate;
}