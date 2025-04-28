#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance)
{
    interestRate = rate;
}

double SavingsAccount::calculateInterest() const
{
    return getBalance() * interestRate;
}