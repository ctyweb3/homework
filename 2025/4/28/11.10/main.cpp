#include <iostream>
#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main()
{
    // Create accounts
    Account account(100.0);
    SavingsAccount savings(100.0, 0.05);
    CheckingAccount checking(100.0, 1.0);

    // Print initial balances
    std::cout << "Initial Account balance: $" << account.getBalance() << std::endl;
    std::cout << "Initial SavingsAccount balance: $" << savings.getBalance() << std::endl;
    std::cout << "Initial CheckingAccount balance: $" << checking.getBalance() << std::endl;

    // Test debit and credit operations
    account.credit(50.0);
    savings.credit(25.0);
    checking.credit(40.0);

    account.debit(75.0);
    savings.debit(50.0);
    checking.debit(50.0);

    // Calculate interest for savings account
    double interest = savings.calculateInterest();
    std::cout << "Interest added to savings: $" << interest << std::endl;

    // Print final balances
    std::cout << "Final Account balance: $" << account.getBalance() << std::endl;
    std::cout << "Final SavingsAccount balance: $" << savings.getBalance() << std::endl;
    std::cout << "Final CheckingAccount balance: $" << checking.getBalance() << std::endl;

    return 0;
}