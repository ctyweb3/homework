#include <iostream>
#include <iomanip>
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"

int main()
{
    // Create package objects
    try
    {
        // Create a regular Package
        Package package("John Doe", "123 Main St", "Anytown", "CA", "12345",
                        "Jane Smith", "456 Oak Ave", "Othertown", "NY", "67890",
                        10.5, 0.5); // 10.5 oz at $0.50 per oz

        // Create a TwoDayPackage
        TwoDayPackage twoDayPackage("Alice Brown", "789 Elm St", "Sometown", "TX", "54321",
                                    "Bob White", "321 Pine Rd", "Hometown", "FL", "98765",
                                    8.25, 0.65, 5.00); // 8.25 oz at $0.65 per oz + $5.00 flat fee

        // Create an OvernightPackage
        OvernightPackage overnightPackage("Carol Green", "159 Maple Dr", "Uptown", "WA", "13579",
                                          "Dave Gray", "753 Cedar Ln", "Downtown", "IL", "24680",
                                          12.75, 0.45, 0.25); // 12.75 oz at $0.45 per oz + $0.25 additional per oz

        // Set output formatting
        std::cout << std::fixed << std::setprecision(2);

        // Display the cost for each package
        std::cout << "Regular Package Cost: $" << package.calculateCost() << std::endl;
        std::cout << "Two-Day Package Cost: $" << twoDayPackage.calculateCost() << std::endl;
        std::cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << std::endl;

        // Demonstrate polymorphism
        std::cout << "\nDemonstrating polymorphism:" << std::endl;

        // Create array of Package pointers
        Package *packages[3] = {&package, &twoDayPackage, &overnightPackage};

        // Process each package polymorphically
        for (int i = 0; i < 3; i++)
        {
            std::cout << "Package " << (i + 1) << " Cost: $" << packages[i]->calculateCost() << std::endl;
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}