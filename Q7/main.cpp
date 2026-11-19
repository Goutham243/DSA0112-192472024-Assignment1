
#include <iostream>
using namespace std;

constexpr long long MIN_BALANCE_PAISE = 5000;

// PROCEDURAL APPROACH

bool proceduralCanTravel(long long balance, long long fare)
{
    return balance - fare >= MIN_BALANCE_PAISE;
}

void proceduralDeduct(long long &balance, long long fare)
{
    if (proceduralCanTravel(balance, fare))
    {
        balance -= fare;
        cout << "Procedural: Fare deducted successfully\n";
    }
    else
    {
        cout << "Procedural: Travel denied (low balance)\n";
    }
}

// OBJECT-ORIENTED APPROACH

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
        return balance - fare >= MIN_BALANCE_PAISE;
    }

    void deduct(long long fare)
    {
        if (fare >= 0 && canTravel(fare))
        {
            balance -= fare;
            cout << "OOP: Fare deducted successfully\n";
        }
        else
        {
            cout << "OOP: Travel denied (low balance or invalid fare)\n";
        }
    }

    void displayBalance() const
    {
        cout << "Balance: Rs " << balance / 100
             << "." << (balance % 100 < 10 ? "0" : "")
             << balance % 100 << "\n";
    }
};

int main()
{
    cout << "METRO SMART CARD SYSTEM\n\n";

    // Procedural implementation
    long long balance = 10000;
    long long fare = 3000;

    cout << "PROCEDURAL APPROACH\n";
    proceduralDeduct(balance, fare);
    cout << "Balance: Rs " << balance / 100 << "."
         << (balance % 100 < 10 ? "0" : "")
         << balance % 100 << "\n\n";

    // Object-oriented implementation
    cout << "OBJECT-ORIENTED APPROACH\n";
    SmartCard card(10000);

    card.deduct(3000);
    card.displayBalance();

    // Test low balance
    card.deduct(2000);
    card.displayBalance();

    return 0;
}
