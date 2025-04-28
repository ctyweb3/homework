#include <iostream>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

using namespace std;

int main()
{
    // Create addresses
    Address sender = {"John Sender", "123 Main St", "Anytown", "CA", "12345"};
    Address recipient = {"Jane Recipient", "456 Oak Ave", "Othertown", "NY", "67890"};

    // Create package objects
    Package package(sender, recipient, 10.0, 0.5);                         // 10 oz, $0.50 per oz
    TwoDayPackage twoDayPackage(sender, recipient, 10.0, 0.5, 2.0);        // $2.00 flat fee
    OvernightPackage overnightPackage(sender, recipient, 10.0, 0.5, 0.25); // $0.25 additional per oz

    // Calculate and display costs
    cout << "Regular Package Cost: $" << package.calculateCost() << endl;
    cout << "Two-Day Package Cost: $" << twoDayPackage.calculateCost() << endl;
    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;

    return 0;
}