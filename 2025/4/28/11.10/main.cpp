#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

int main()
{
    // Create Account object
    Account account(1000.0);
    std::cout << "Account initial balance: " << account.getBalance() << std::endl;

    // Test credit and debit operations
    account.credit(500.0);
    std::cout << "Account balance after credit: " << account.getBalance() << std::endl;

    account.debit(200.0);
    std::cout << "Account balance after debit: " << account.getBalance() << std::endl;

    // Try to debit more than the balance
    account.debit(2000.0);
    std::cout << "Account balance after failed debit: " << account.getBalance() << std::endl;

    // Create SavingsAccount object
    SavingsAccount savings(2000.0, 0.05);
    std::cout << "\nSavings initial balance: " << savings.getBalance() << std::endl;

    // Calculate and add interest
    double interest = savings.calculateInterest();
    std::cout << "Interest earned: " << interest << std::endl;

    savings.credit(interest);
    std::cout << "Savings balance after adding interest: " << savings.getBalance() << std::endl;

    // Create CheckingAccount object
    CheckingAccount checking(3000.0, 1.0);
    std::cout << "\nChecking initial balance: " << checking.getBalance() << std::endl;

    // Test credit operation with fee
    checking.credit(500.0);
    std::cout << "Checking balance after credit (with fee): " << checking.getBalance() << std::endl;

    // Test debit operation with fee
    checking.debit(200.0);
    std::cout << "Checking balance after debit (with fee): " << checking.getBalance() << std::endl;

    // Try to debit more than the balance
    checking.debit(5000.0);
    std::cout << "Checking balance after failed debit (no fee charged): " << checking.getBalance() << std::endl;

    return 0;
}