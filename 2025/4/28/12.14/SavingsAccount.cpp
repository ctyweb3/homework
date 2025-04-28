#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(const std::string &number, double initialBalance, double rate)
    : Account(number, initialBalance)
{
    // Validate interest rate
    if (rate < 0.0)
    {
        std::cout << "Error: Interest rate cannot be negative. Setting rate to 0." << std::endl;
        interestRate = 0.0;
    }
    else
    {
        interestRate = rate;
    }
}

double SavingsAccount::calculateInterest() const
{
    // Calculate interest amount based on current balance and interest rate
    return getBalance() * interestRate;
}