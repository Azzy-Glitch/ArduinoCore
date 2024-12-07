#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    char arith;
    char choice;

    do
    {
        cout << "Enter the first fraction (a/b): ";
        cin >> a >> b;

        cout << "Enter an operator (+, -, *, /): ";
        cin >> arith;

        cout << "Enter the second fraction (c/d): ";
        cin >> c >> d;

        int numerator = 0;
        int denominator = 0;

        if (arith == '+')
        {
            numerator = a * d + b * c;
            denominator = b * d;
        }
        else if (arith == '-')
        {
            numerator = a * d - b * c;
            denominator = b * d;
        }
        else if (arith == '*')
        {
            numerator = a * c;
            denominator = b * d;
        }
        else if (arith == '/')
        {
            numerator = a * d;
            denominator = b * c;
        }
        else
        {
            cout << "Invalid operator! Please use +, -, *, or /." << endl;
            continue;
        }

        cout << "The result is: " << numerator << "/" << denominator << endl;

        cout << "Do you want to continue? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!" << endl;
    return 0;
}
