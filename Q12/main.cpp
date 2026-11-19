
#include <iostream>
#include <iomanip>
using namespace std;

// Zone definitions
enum class Zone
{
    Inner,
    Middle,
    Outer,
    Airport
};

// Fare constants in paise
constexpr long long BASE_FARE[] = {
    1000, 2000, 3000, 6000
};

constexpr int PEAK_SURCHARGE = 20;
constexpr int WEEKEND_DISCOUNT = 10;
constexpr long long MIN_BALANCE = 5000;

// Monthly Pass Class
class MonthlyPass
{
private:
    Zone zone1;
    Zone zone2;

public:
    MonthlyPass(Zone z1, Zone z2)
    {
        zone1 = z1;
        zone2 = z2;
    }

    bool isCovered(Zone z) const
    {
        return (z == zone1 || z == zone2);
    }
};

// Smart Card Class
class SmartCard
{
private:
    long long balance;

public:
    SmartCard(long long initialBalance)
    {
        balance = initialBalance;
    }

    bool canTravel(long long fare) const
    {
        return fare >= 0 &&
               balance - fare >= MIN_BALANCE;
    }

    void deduct(long long fare)
    {
        balance -= fare;
    }

    void displayBalance() const
    {
        cout << "Balance: Rs "
             << balance / 100 << "."
             << setw(2) << setfill('0')
             << balance % 100 << setfill(' ') << '\n';
    }
};

// Calculate fare
long long calculateFare(
    Zone zone,
    bool peak,
    bool weekend,
    const MonthlyPass& pass)
{
    // Monthly pass gives unlimited travel
    // in the two selected zones
    if (pass.isCovered(zone))
    {
        return 0;
    }

    int index = static_cast<int>(zone);
    long long fare = BASE_FARE[index];

    // Weekend discount does not combine
    // with peak surcharge
    if (weekend)
    {
        fare -= fare * WEEKEND_DISCOUNT / 100;
    }
    else if (peak)
    {
        fare += fare * PEAK_SURCHARGE / 100;
    }

    return fare;
}

// Display fare
void displayFare(long long fare)
{
    cout << "Fare: Rs "
         << fare / 100 << "."
         << setw(2) << setfill('0')
         << fare % 100 << setfill(' ') << '\n';
}

int main()
{
    cout << "METRO SMART CARD - UPDATED FARE SYSTEM\n\n";

    SmartCard card(30000);

    // Monthly pass covers Inner and Middle zones
    MonthlyPass pass(Zone::Inner, Zone::Middle);

    // Test 1: Airport zone during peak hours
    cout << "Test 1: Airport - Peak Hour\n";

    long long fare1 = calculateFare(
        Zone::Airport, true, false, pass);

    displayFare(fare1);

    if (card.canTravel(fare1))
    {
        card.deduct(fare1);
        cout << "Travel Allowed\n";
    }
    else
    {
        cout << "Travel Denied\n";
    }

    card.displayBalance();

    // Test 2: Airport zone during weekend
    cout << "\nTest 2: Airport - Weekend\n";

    long long fare2 = calculateFare(
        Zone::Airport, true, true, pass);

    displayFare(fare2);

    if (card.canTravel(fare2))
    {
        card.deduct(fare2);
        cout << "Travel Allowed\n";
    }
    else
    {
        cout << "Travel Denied\n";
    }

    card.displayBalance();

    // Test 3: Inner zone using monthly pass
    cout << "\nTest 3: Inner - Monthly Pass\n";

    long long fare3 = calculateFare(
        Zone::Inner, false, false, pass);

    displayFare(fare3);

    if (card.canTravel(fare3))
    {
        card.deduct(fare3);
        cout << "Travel Allowed - Monthly Pass\n";
    }
    else
    {
        cout << "Travel Denied\n";
    }

    card.displayBalance();

    // Test 4: Outer zone normal journey
    cout << "\nTest 4: Outer - Normal Journey\n";

    long long fare4 = calculateFare(
        Zone::Outer, false, false, pass);

    displayFare(fare4);

    if (card.canTravel(fare4))
    {
        card.deduct(fare4);
        cout << "Travel Allowed\n";
    }
    else
    {
        cout << "Travel Denied\n";
    }

    card.displayBalance();

    return 0;
}
