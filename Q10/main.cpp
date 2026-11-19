
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main()
{
    const long long farePaise = 1010; // Rs 10.10
    const double fareRupees = 10.10;

    long long journeyCounts[] = {
        20000, 500000, 3000000
    };

    cout << "METRO FARE COLLECTION COMPARISON\n\n";

    cout << fixed << setprecision(10);

    for (long long journeys : journeyCounts)
    {
        // Integer paise calculation
        long long totalPaise = farePaise * journeys;

        // Double rupees calculation
        double doubleTotal = 0.0;

        for (long long i = 0; i < journeys; i++)
        {
            doubleTotal += fareRupees;
        }

        double integerTotal = static_cast<double>(totalPaise) / 100.0;

        double difference = doubleTotal - integerTotal;

        cout << "Journeys: " << journeys << '\n';

        cout << "Integer Paise Total: Rs "
             << integerTotal << '\n';

        cout << "Double Total: Rs "
             << doubleTotal << '\n';

        cout << "Difference: Rs "
             << difference << "\n\n";
    }

    // Check integer overflow
    long long networkTotal = farePaise * 3000000LL;

    cout << "INTEGER OVERFLOW ANALYSIS\n";

    cout << "INT_MAX: " << INT_MAX << '\n';

    cout << "Network Total in Paise: "
         << networkTotal << '\n';

    if (networkTotal > INT_MAX)
    {
        cout << "Result: int will overflow\n";
    }
    else
    {
        cout << "Result: int can store the total\n";
    }

    cout << "\nDATA TYPE SIZE COMPARISON\n";

    cout << "int: " << sizeof(int) << " bytes\n";
    cout << "long long: " << sizeof(long long) << " bytes\n";
    cout << "double: " << sizeof(double) << " bytes\n";

    cout << "\nCONCLUSION\n";
    cout << "Integer paise provides exact money calculations.\n";
    cout << "Long long prevents overflow for network collections.\n";
    cout << "Double may introduce floating-point errors.\n";

    return 0;
}
