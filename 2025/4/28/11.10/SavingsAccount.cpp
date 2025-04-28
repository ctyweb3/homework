#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double initialBalance, double rate)
    : Account(initialBalance)
{
    interestRate = (rate >= 0.0) ? rate : 0.0;
}

double SavingsAccount::calculateInterest()
{
    double interest = balance * interestRate;
    credit(interest);
    return interest;
}