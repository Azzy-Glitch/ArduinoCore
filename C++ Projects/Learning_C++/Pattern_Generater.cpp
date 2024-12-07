#include <iostream>
using namespace std;

int main()
{
    int option, i, j, k, n;
    do
    {
        cout << "\n\t\tMENU";
        cout << "\n---------------------------------";
        cout << "\n1. Left Half Triangle";
        cout << "\n2. Inverted Left Half Triangle";
        cout << "\n3. Right Half Triangle";
        cout << "\n4. Inverted Right Half Triangle";
        cout << "\n5. Pyramid";
        cout << "\n6. Inverted Pyramid";
        cout << "\n7. Exit";
        cout << "\n---------------------------------";
        cout << "\nChoose an option (1-7): ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter the number of rows: ";
            cin >> n;
            cout << "\nLeft Half Triangle:\n";
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= i; j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        case 2:
            cout << "Enter the number of rows: ";
            cin >> n;
            cout << "\nInverted Left Half Triangle:\n";
            for (i = n; i >= 1; i--)
            {
                for (j = 1; j <= i; j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        case 3:
            cout << "Enter the number of rows: ";
            cin >> n;
            cout << "\nRight Half Triangle:\n";
            for (i = 1; i <= n; i++)
            {
                for (k = n - i; k > 0; k--)
                {
                    cout << "  ";
                }
                for (j = 1; j <= i; j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        case 4:
            cout << "Enter the number of rows: ";
            cin >> n;
            cout << "\nInverted Right Half Triangle:\n";
            for (i = n; i >= 1; i--)
            {
                for (k = n - i; k > 0; k--)
                {
                    cout << "  ";
                }
                for (j = 1; j <= i; j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        case 5:
            cout << "Enter the number of rows: ";
            cin >> n;
            cout << "\nPyramid:\n";
            for (i = 1; i <= n; i++)
            {
                for (k = n - i; k > 0; k--)
                {
                    cout << "  ";
                }
                for (j = 1; j <= (2 * i - 1); j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        case 6:
            cout << "Enter the number of rows: ";
            cin >> n;
            cout << "\nInverted Pyramid:\n";
            for (i = n; i >= 1; i--)
            {
                for (k = n - i; k > 0; k--)
                {
                    cout << "  ";
                }
                for (j = 1; j <= (2 * i - 1); j++)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            break;

        case 7:
            cout << "\nExiting menu. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid input. Please choose a valid option (1-7).\n";
        }
    } while (option != 7);

    return 0;
}
