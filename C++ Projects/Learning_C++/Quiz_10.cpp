// Create a menu-driven calculator that performs basic arithmetic operations. The program should display a menu with options for addition, subtraction, multiplication, and division.

// Use a switch statement to handle the operation selection.
// Inside each case, use if-else statements to check for division by zero.
// Use escape sequences to format the output neatly.
#include <iostream>

using namespace std;

int main()
{
    double Num_1, Num_2, Result;
    int choice;

    cout << "Menu:\n";

    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";

    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Result = Num_1 + Num_2;
        cout << "Result: " << Result << endl;
        break;
    case 2:
        Result = Num_1 - Num_2;
        cout << "Result: " << Result << endl;
        break;
    case 3:
        Result = Num_1 * Num_2;
        cout << "Result: " << Result << endl;
        break;
    case 4:
        if (Num_2 == 0)
        {
            cout << "Error: Division by zero!" << endl;
        }
        else
        {
            Result = Num_1 / Num_2;
            cout << "Result: " << Result << endl;
        }
        break;

    default:
        cout << "Error: Division by zero!" << endl;
        break;
    }
    return 0;
}