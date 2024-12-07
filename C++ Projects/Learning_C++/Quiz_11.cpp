// Develop a C++ program that takes the temperature in Celsius as input and provides a weather advisory based on the following criteria:

// Below 0°C: "Freezing weather"
// 0°C to 10°C: "Cold weather"
// 11°C to 20°C: "Cool weather"
// 21°C to 30°C: "Warm weather"
// Above 30°C: "Hot weather"
// Use a switch statement to categorize the temperature and if-else statements
//  for additional advisory messages based on user input
//   (e.g., "Do you want to know about wind chill? (yes/no)").
//    Use logical operators to combine conditions.
#include <iostream>

using namespace std;

int main()
{
    int temperature;

    cout << "Enter temperature in Celcius(-100 , 100): " << endl;
    cin >> temperature;

    switch (temperature / 10)
    {
    case -10 ... - 1:
    case 0:
        if (temperature < 0)
        {
            cout << "Freezing weather: " << endl;
        }
        else
        {
            cout << "Cold weather: " << endl;
        }
        break;
    case 1:
        cout << "Cool weather: " << endl;
        break;
    case 2:
        cout << "Warm weather: " << endl;
        break;
    case 3 ... 9:
        cout << "Hot weather: ";
        break;
    default:
        cout << "Invalid input!" << endl;
        break;
    }

    string choice;

    cout << "Do you want to know about wind chill? (yes/no): ";
    cin >> choice;

    if (choice == "yes")
    {
        cout << "Wind chill can make it feel colder than the actual temperature!" << endl;
    }
    else if (choice == "no")
    {
        cout << "Okay, no additional information will be provided." << endl;
    }
    else
    {
        cout << "Invalid input: " << endl;
    }
    return 0;
}