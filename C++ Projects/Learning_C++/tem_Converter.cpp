#include <iostream>

using namespace std;

void CelsiusToFahrenheit()
{
    double Celsius;
    cout << "Enter temperature in \"Celcius\" to convert into \"Fahrenheit\": " << endl;
    cin >> Celsius;
    double Fahrenheit = (Celsius * 9.0 / 5.0) + 32.0;
    cout << "The converted temperature from \"Celsius\" to \"Fahrenheit\" is:  " << Fahrenheit << endl;
    cout << endl;
}

void FahrenheitToCelsius()
{
    double fahrenheit;
    cout << "Enter temperature in \"Fahrenheit\" to convert into \"Celcius\": " << endl;
    cin >> fahrenheit;
    double Celsius = (fahrenheit - 32.0 * 9.0 / 5.0) * 5.0 / 9.0;
    cout << "The converted temperature from \"Fahrenheit\" to \"Celcius\" is:  " << Celsius << endl;
    cout << endl;
}

int main()
{
    int unit;
    cout << "Type 1 to convert Fahrenheit to Celsius \"OR\" 2 to convert Celsius to Fahrenheit : "
         << endl;
    cin >> unit;
    if (unit == 1)
    {
        FahrenheitToCelsius();
    }
    else if (unit == 2)
    {
        CelsiusToFahrenheit();
    }
    else
    {
        cout << "Invalid unit. Please enter C for Celsius or F for Fahrenheit." << endl;
    }

    return 0;
}