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
    // Create addresses
    Address sender1 = {"John Smith", "123 Main St", "Anytown", "NY", "12345"};
    Address recipient1 = {"Jane Doe", "456 Oak Ave", "Othertown", "CA", "67890"};

    Address sender2 = {"Alice Johnson", "789 Pine Rd", "Smallville", "TX", "23456"};
    Address recipient2 = {"Bob Williams", "321 Elm St", "Bigcity", "IL", "78901"};

    Address sender3 = {"Mary Wilson", "555 Cedar Dr", "Midtown", "FL", "34567"};
    Address recipient3 = {"Tom Davis", "888 Maple Ave", "Downtown", "WA", "45678"};

    // Create a vector of Package pointers
    vector<Package *> packages;

    // Add packages to the vector
    packages.push_back(new Package(sender1, recipient1, 10.5, 0.5));
    packages.push_back(new TwoDayPackage(sender2, recipient2, 8.25, 0.65, 5.0));
    packages.push_back(new OvernightPackage(sender3, recipient3, 12.75, 0.45, 0.25));

    double totalShippingCost = 0.0;

    // Process each package polymorphically
    cout << fixed << setprecision(2);

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