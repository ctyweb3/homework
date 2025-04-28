#include <iostream>
#include <vector>
#include <iomanip>
#include <typeinfo>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

// Function to display account information
void displayAccount(const Account &account)
{
    cout << "Account Number: " << account.getAccountNumber()
         << " | Balance: $" << fixed << setprecision(2) << account.getBalance() << endl;
}

int main()
{
    // Create a vector of Account pointers
    vector<Account *> accounts;

    // Create some SavingsAccount and CheckingAccount objects
    accounts.push_back(new SavingsAccount("S1001", 1000.00, 0.05));  // $1000 with 5% interest
    accounts.push_back(new SavingsAccount("S1002", 2000.00, 0.03));  // $2000 with 3% interest
    accounts.push_back(new CheckingAccount("C2001", 500.00, 1.50));  // $500 with $1.50 fee
    accounts.push_back(new CheckingAccount("C2002", 1200.00, 0.75)); // $1200 with $0.75 fee

    // Display the initial account information
    cout << "Initial Account Information:" << endl;
    cout << "=================================" << endl;
    for (size_t i = 0; i < accounts.size(); ++i)
    {
        cout << i + 1 << ". ";
        displayAccount(*accounts[i]);
    }
    cout << endl;

    // Process each account
    for (size_t i = 0; i < accounts.size(); ++i)
    {
        cout << "Processing Account " << i + 1 << " (" << accounts[i]->getAccountNumber() << "):" << endl;
        cout << "=================================" << endl;

        double amount;

        // Ask for withdrawal amount
        cout << "Enter amount to withdraw: $";
        cin >> amount;

        if (accounts[i]->debit(amount))
        {
            cout << "Withdrawal successful." << endl;
        }

        // Ask for deposit amount
        cout << "Enter amount to deposit: $";
        cin >> amount;

        accounts[i]->credit(amount);

        // Calculate interest for SavingsAccount
        SavingsAccount *savingsPtr = dynamic_cast<SavingsAccount *>(accounts[i]);
        if (savingsPtr != nullptr)
        {
            double interest = savingsPtr->calculateInterest();
            cout << "Interest earned: $" << fixed << setprecision(2) << interest << endl;
            savingsPtr->credit(interest);
        }

        // Display updated balance
        cout << "Updated balance: $" << fixed << setprecision(2) << accounts[i]->getBalance() << endl;
        cout << endl;
    }

    // Display final account information
    cout << "Final Account Information:" << endl;
    cout << "=================================" << endl;
    for (size_t i = 0; i < accounts.size(); ++i)
    {
        cout << i + 1 << ". ";
        displayAccount(*accounts[i]);
    }

    // Clean up memory
    for (Account *accountPtr : accounts)
    {
        delete accountPtr;
    }

    return 0;
}