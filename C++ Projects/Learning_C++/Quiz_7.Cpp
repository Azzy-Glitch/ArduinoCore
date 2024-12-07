#include <iostream>
using namespace std;

int main()
{
    int units;
    float bill = 0;

    cout << "Enter the number of units consumed: ";
    cin >> units;

    if (units <= 100)
    {
        bill = units * 5;
    }
    else if (units <= 200)
    {
        bill = 100 * 5 + (units - 100) * 7;
    }
    else
    {
        bill = 100 * 5 + 100 * 7 + (units - 200) * 10;
    }

    cout << "The total electricity bill is: Rs. " << bill << endl;

    return 0;
}
