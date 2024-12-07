#include <iostream>

using namespace std;

int main()
{
    float gallons;
    float cubic_feet;

    cout << "Enter number of gallons: ";
    cin >> gallons;

    cubic_feet = gallons / 7.481;

    cout << "The number of cubic feet is: " << cubic_feet ;

    return 0;
}