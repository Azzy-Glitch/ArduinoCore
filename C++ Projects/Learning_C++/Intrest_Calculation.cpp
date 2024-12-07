#include <iostream>
using namespace std;

int main()
{
    double amount, tamount, interest;
    int years = 0;

    cout << "Enter initial amount: ";
    cin >> amount;
    if (amount <= 0)
    {
        cout << "Initial amount must be positive!" << endl;
        return 1;
    }

    cout << "Enter target amount: ";
    cin >> tamount;
    if (tamount <= amount)
    {
        cout << "Target amount must be greater than the initial amount!" << endl;
        return 1;
    }

    cout << "Enter interest rate in percentage: ";
    cin >> interest;

    if (interest <= 0)
    {
        cout << "Interest rate must be positive!" << endl;
        return 1;
    }

    while (amount < tamount)
    {
        amount += amount * (interest / 100);
        years++;
    }

    cout << "At the end of " << years << " years, the target amount will be reached." << endl;

    return 0;
}
