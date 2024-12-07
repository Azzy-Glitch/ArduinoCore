#include <iostream>
using namespace std;

int main()
{
    int guests, chairs;

    cout << "Enter the number of guests: ";
    cin >> guests;

    cout << "Enter the number of chairs: ";
    cin >> chairs;

    if (guests < chairs)
    {
        cout << "Error: Number of guests must be greater than or equal to the number of chairs." << endl;
        return 1;
    }
    int arrangements = 1;

    for (int i = 0; i < chairs; i++)
    {
        arrangements *= (guests - i);
    }
    
    cout << "The number of possible arrangements is: " << arrangements << endl;

    return 0;
}
