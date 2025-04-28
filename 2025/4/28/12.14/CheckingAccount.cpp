#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(const std::string &number, double initialBalance, double fee)
    : Account(number, initialBalance)
{
    // Validate transaction fee
    if (fee < 0.0)
    {
        std::cout << "Error: Transaction fee cannot be negative. Setting fee to 0." << std::endl;
        transactionFee = 0.0;
    }
    else
    {
        transactionFee = fee;
    }
}

void CheckingAccount::credit(double amount)
{
    if (amount > 0.0)
    {
        // First add the amount
        Account::credit(amount);

        // Then charge the transaction fee
        if (getBalance() >= transactionFee)
        {
            Account::debit(transactionFee);
            std::cout << "$" << transactionFee << " transaction fee charged." << std::endl;
        }
        else
        {
            std::cout << "Unable to charge transaction fee. Insufficient funds." << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Credit amount must be positive." << std::endl;
    }
}

bool CheckingAccount::debit(double amount)
{
    // Calculate total withdrawal amount including fee
    double totalDebit = amount + transactionFee;

    if (totalDebit > getBalance())
    {
        std::cout << "Debit amount plus transaction fee exceeded account balance." << std::endl;
        return false;
    }

    // Perform the debit operation
    bool success = Account::debit(amount);

    if (success)
    {
        // Charge the transaction fee
        Account::debit(transactionFee);
        std::cout << "$" << transactionFee << " transaction fee charged." << std::endl;
    }

    return success;
}