
#include <iostream>
#include <iomanip>
#include <climits>
#include <limits>
using namespace std;

int main()
{
    // Data types used in Metro Fare System
    bool peakHour = true;
    char zone = 'A';
    int hour = 9;
    unsigned int zoneNumber = 3;
    long long balancePaise = 10000;
    float temperature = 32.5f;
    double fareRupees = 10.50;
    auto journeys = 3000000LL;

    // Display values and sizes
    cout << "METRO SMART CARD - DATA TYPES\n\n";

    cout << "Peak Hour: " << peakHour << endl;
    cout << "Zone: " << zone << endl;
    cout << "Hour: " << hour << endl;
    cout << "Zone Number: " << zoneNumber << endl;
    cout << "Balance (Paise): " << balancePaise << endl;
    cout << "Temperature: " << temperature << endl;
    cout << "Fare (Rupees): " << fareRupees << endl;
    cout << "Daily Journeys: " << journeys << endl;

    cout << "\nSIZE OF DATA TYPES\n";
    cout << "bool: " << sizeof(bool) << " bytes\n";
    cout << "char: " << sizeof(char) << " bytes\n";
    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "unsigned int: " << sizeof(unsigned int) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
    cout << "float: " << sizeof(float) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";

    // Money calculation using integer paise
    long long farePaise = 1200;
    long long totalPaise = farePaise * journeys;

    cout << "\nMONEY CALCULATION\n";
    cout << "Fare per journey: Rs 12.00\n";
    cout << "Total collection: Rs "
         << totalPaise / 100 << "."
         << setw(2) << setfill('0')
         << totalPaise % 100 << setfill(' ') << endl;

    // Integer limits
    cout << "\nINTEGER LIMITS\n";
    cout << "INT_MAX: " << INT_MAX << endl;
    cout << "INT_MIN: " << INT_MIN << endl;
    cout << "LLONG_MAX: " << LLONG_MAX << endl;

    // Demonstrate double precision
    double doubleTotal = 0.0;
    long long paiseTotal = 0;

    for (int i = 0; i < 1000000; i++)
    {
        doubleTotal += 0.10;
        paiseTotal += 10;
    }

    cout << "\nPRECISION COMPARISON\n";
    cout << fixed << setprecision(10);
    cout << "Double total: Rs " << doubleTotal << endl;
    cout << "Integer paise total: Rs "
         << static_cast<double>(paiseTotal) / 100 << endl;

    cout << "\nCONCLUSION\n";
    cout << "Integer paise provides exact money calculations.\n";
    cout << "Long long is suitable for large network collections.\n";

    return 0;
}
