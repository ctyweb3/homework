#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(const std::string &number, double initialBalance, double fee)
    : Account(number, initialBalance)
{
    if (fee < 0.0)
    {
        std::cout << "Error: Transaction fee cannot be negative. Setting to 0.\n";
        transactionFee = 0.0;
    }
    else
    {
        transactionFee = fee;
    }
}

void CheckingAccount::credit(double amount)
{
    if (amount <= 0.0)
    {
        std::cout << "Error: Credit amount must be positive.\n";
        return;
    }

    Account::credit(amount);

    // Charge transaction fee
    if (balance >= transactionFee)
    {
        balance -= transactionFee;
        std::cout << "$" << transactionFee << " transaction fee charged.\n";
    }
    else
    {
        std::cout << "Warning: Unable to charge transaction fee due to insufficient funds.\n";
    }
}

bool CheckingAccount::debit(double amount)
{
    if (amount <= 0.0)
    {
        std::cout << "Error: Debit amount must be positive.\n";
        return false;
    }

    // Check if there's enough to cover both amount and fee
    if (amount + transactionFee > balance)
    {
        std::cout << "Error: Debit amount plus transaction fee exceeds balance.\n";
        return false;
    }

    // Withdraw the amount
    balance -= amount;

    // Charge transaction fee
    balance -= transactionFee;
    std::cout << "$" << transactionFee << " transaction fee charged.\n";

    return true;
}