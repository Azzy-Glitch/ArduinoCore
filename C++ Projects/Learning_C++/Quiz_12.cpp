// Write a C++ program that takes an age as input and classifies it into different groups:

// Child (0-12)
// Teenager (13-19)
// Adult (20-64)
// Senior (65 and above)
// // Use a switch statement to classify the age and nested if statements
//  to check for specific conditions (e.g., if the person is a teenager,
//   check if they are 18 or older). Use escape sequences for clear output formatting.
#include <iostream>

using namespace std;

int main()
{
    int age;
    cout << "Enter your age: " << endl;
    cin >> age;

    switch (age / 10)
    {
    case 0:
    case 1:
        if (age <= 12)
        {
            cout << "You are a Child" << endl;
        }
        else if (age <= 19)
        {
            if (age >= 18)
            {
                cout << "You are a Teenager (18 or older).\n";
            }
            else
            {
                cout << "You are a Teenager.\n";
            }
        }
        break;
    case 2 ... 9:
        if (age <= 64)
        {
            cout << "You are Adult" << endl;
        }
        else
        {
            cout << "You are Seniour" << endl;
        }
        break;
    default:
        cout << "Invalid Input!" << endl;
        break;
    }
    return 0;
}