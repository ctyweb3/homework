#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

int main()
{
    // Create a vector of Account pointers
    vector<Account *> accounts;

    // Create accounts and add them to the vector
    accounts.push_back(new SavingsAccount("S1001", 1000.00, 0.05));  // $1000 with 5% interest
    accounts.push_back(new SavingsAccount("S1002", 2000.00, 0.03));  // $2000 with 3% interest
    accounts.push_back(new CheckingAccount("C2001", 500.00, 1.50));  // $500 with $1.50 fee
    accounts.push_back(new CheckingAccount("C2002", 1200.00, 0.75)); // $1200 with $0.75 fee

    // Display the initial account information
    cout << fixed << setprecision(2);
    cout << "Initial Account Information:" << endl;
    cout << "=================================" << endl;

    for (size_t i = 0; i < accounts.size(); ++i)
    {
        cout << "Account " << accounts[i]->getAccountNumber()
             << " Balance: $" << accounts[i]->getBalance() << endl;
    }
    cout << endl;

    // Process each account
    for (size_t i = 0; i < accounts.size(); ++i)
    {
        cout << "Processing Account " << accounts[i]->getAccountNumber() << ":" << endl;
        cout << "=================================" << endl;

        // Withdraw some money
        double withdrawAmount = 50.0 * (i + 1);
        cout << "Withdrawing $" << withdrawAmount << "... ";
        if (accounts[i]->debit(withdrawAmount))
        {
            cout << "Successful" << endl;
        }

        // Deposit some money
        double depositAmount = 100.0 * (i + 1);
        cout << "Depositing $" << depositAmount << "... ";
        accounts[i]->credit(depositAmount);
        cout << "Successful" << endl;

        // Calculate interest for SavingsAccount
        SavingsAccount *savingsPtr = dynamic_cast<SavingsAccount *>(accounts[i]);
        if (savingsPtr)
        {
            double interest = savingsPtr->calculateInterest();
            cout << "Interest earned: $" << interest << endl;
            savingsPtr->credit(interest);
        }

        // Display updated balance
        cout << "Updated balance: $" << accounts[i]->getBalance() << endl
             << endl;
    }

    // Display final account information
    cout << "Final Account Information:" << endl;
    cout << "=================================" << endl;

    for (size_t i = 0; i < accounts.size(); ++i)
    {
        cout << "Account " << accounts[i]->getAccountNumber()
             << " Balance: $" << accounts[i]->getBalance() << endl;
    }

    // Clean up memory
    for (auto accountPtr : accounts)
    {
        delete accountPtr;
    }

    return 0;
}