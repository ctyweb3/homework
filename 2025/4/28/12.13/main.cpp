#include <iostream>
#include <vector>
#include <iomanip>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

// Function to print address as it would appear on a mailing label
void printMailingLabel(const Package &package)
{
    cout << "Sender:\n"
         << package.getSenderName() << endl
         << package.getSenderAddress() << endl
         << package.getSenderCity() << ", "
         << package.getSenderState() << " "
         << package.getSenderZip() << endl;

    cout << "\nRecipient:\n"
         << package.getRecipientName() << endl
         << package.getRecipientAddress() << endl
         << package.getRecipientCity() << ", "
         << package.getRecipientState() << " "
         << package.getRecipientZip() << endl;
}

int main()
{
    // Create vector of Package pointers to hold various types of packages
    vector<Package *> packages;

    // Add packages to the vector
    packages.push_back(new Package("John Smith", "123 Main St", "Anytown", "NY", "12345",
                                   "Jane Doe", "456 Oak Ave", "Othertown", "CA", "67890",
                                   10.5, 0.5)); // 10.5 oz at $0.50 per oz

    packages.push_back(new TwoDayPackage("Alice Johnson", "789 Pine Rd", "Smallville", "TX", "23456",
                                         "Bob Williams", "321 Elm St", "Bigcity", "IL", "78901",
                                         8.25, 0.65, 5.0)); // 8.25 oz at $0.65 per oz plus $5.00 flat fee

    packages.push_back(new OvernightPackage("Mary Wilson", "555 Cedar Dr", "Midtown", "FL", "34567",
                                            "Tom Davis", "888 Maple Ave", "Downtown", "WA", "45678",
                                            12.75, 0.45, 0.25)); // 12.75 oz at $0.45 per oz plus $0.25 additional per oz

    double totalShippingCost = 0.0; // To track total shipping cost for all packages

    // Process each package polymorphically
    cout << fixed << setprecision(2); // Set output formatting for costs

    for (size_t i = 0; i < packages.size(); ++i)
    {
        cout << "\n==========================================\n";
        cout << "Package " << (i + 1) << ":\n";

        // Print mailing label information
        printMailingLabel(*packages[i]);

        // Calculate and display cost
        double cost = packages[i]->calculateCost();
        cout << "\nShipping Cost: $" << cost << endl;

        // Add to total
        totalShippingCost += cost;
    }

    // Display total shipping cost
    cout << "\n==========================================\n";
    cout << "Total Shipping Cost for All Packages: $" << totalShippingCost << endl;

    // Free memory
    for (auto pkg : packages)
    {
        delete pkg;
    }

    return 0;
}