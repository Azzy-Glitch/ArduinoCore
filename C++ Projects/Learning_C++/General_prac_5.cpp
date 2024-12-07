#include <iostream>

using namespace std;

int main()
{
    double C, F;
    cout << "Enter temperature in Celsius: ";
    cin >> C;
    F = (C * 9 / 5) + 32;
    cout << "Temperature in Fahrenheit: " << F;

    return 0;
}