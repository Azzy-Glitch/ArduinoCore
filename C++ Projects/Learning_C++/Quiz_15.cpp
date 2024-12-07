#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, num;
    float a_1, b_1, angle;
    int key;

    do
    {
        // Display the menu
        cout << "\n\tCalculator Menu\n";
        cout << "1. Addition of two integers\n";
        cout << "2. Subtraction of two integers\n";
        cout << "3. Multiplication of two integers\n";
        cout << "4. Division of two integers\n";
        cout << "5. Addition of two float numbers\n";
        cout << "6. Subtraction of two float numbers\n";
        cout << "7. Multiplication of two float numbers\n";
        cout << "8. Division of two float numbers\n";
        cout << "9. Sine\n";
        cout << "10. Cosine\n";
        cout << "11. Tangent\n";
        cout << "12. Square root\n";
        cout << "13. Square\n";
        cout << "14. Cube\n";
        cout << "15. Exit\n";
        cout << "Please enter your choice: ";
        cin >> key;

        switch (key)
        {
        case 1:
            cout << "Enter two integers: ";
            cin >> a >> b;
            cout << "Sum is: " << a + b << endl;
            break;
        case 2:
            cout << "Enter two integers: ";
            cin >> a >> b;
            cout << "Difference is: " << a - b << endl;
            break;
        case 3:
            cout << "Enter two integers: ";
            cin >> a >> b;
            cout << "Product is: " << a * b << endl;
            break;
        case 4:
            cout << "Enter two integers: ";
            cin >> a >> b;
            if (b != 0)
            {
                cout << "Quotient is: " << static_cast<float>(a) / b << endl;
            }
            else
            {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        case 5:
            cout << "Enter two float numbers: ";
            cin >> a_1 >> b_1;
            cout << "Sum is: " << a_1 + b_1 << endl;
            break;
        case 6:
            cout << "Enter two float numbers: ";
            cin >> a_1 >> b_1;
            cout << "Difference is: " << a_1 - b_1 << endl;
            break;
        case 7:
            cout << "Enter two float numbers: ";
            cin >> a_1 >> b_1;
            cout << "Product is: " << a_1 * b_1 << endl;
            break;
        case 8:
            cout << "Enter two float numbers: ";
            cin >> a_1 >> b_1;
            if (b_1 != 0)
            {
                cout << "Quotient is: " << a_1 / b_1 << endl;
            }
            else
            {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        case 9:
            cout << "Enter angle in degrees: ";
            cin >> angle;
            cout << "Sine is: " << sin(angle * M_PI / 180) << endl;
            break;
        case 10:
            cout << "Enter angle in degrees: ";
            cin >> angle;
            cout << "Cosine is: " << cos(angle * M_PI / 180) << endl;
            break;
        case 11:
            cout << "Enter angle in degrees: ";
            cin >> angle;
            cout << "Tangent is: " << tan(angle * M_PI / 180) << endl;
            break;
        case 12:
            cout << "Enter a number: ";
            cin >> num;
            if (num >= 0)
            {
                cout << "Square root is: " << sqrt(num) << endl;
            }
            else
            {
                cout << "Error: Square root of negative number!" << endl;
            }
            break;
        case 13:
            cout << "Enter a number: ";
            cin >> num;
            cout << "Square is: " << num * num << endl;
            break;
        case 14:
            cout << "Enter a number: ";
            cin >> num;
            cout << "Cube is: " << num * num * num << endl;
            break;
        case 15:
            cout << "Exiting calculator." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (key != 15);

    return 0;
}