#include <iostream>

using namespace std;

int main()
{
    float Units;

    cout << "Enter the number of units: " << endl;
    cin >> Units;

    if (Units <= 100)
    {
        cout << "You pay: Rs " << Units * 5 << endl;
    }
    else if (Units <= 200)
    {
        cout << "You pay: Rs " << Units * 7 << endl;
    }
    else if (Units > 200)
    {
        cout << "You pay: Rs " << Units * 10 << endl;
    }
    return 0;
}