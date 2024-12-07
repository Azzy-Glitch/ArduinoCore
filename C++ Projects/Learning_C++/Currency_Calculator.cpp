#include <iostream>
using namespace std;

int main()
{
    char choice;
    do
    {
        int pounds1, shillings1, pence1;
        int pounds2, shillings2, pence2;
        int totalPounds, totalShillings, totalPence;

        cout << "Enter first amount (e.g., £5.10.6): £";
        char dot;
        cin >> pounds1 >> dot >> shillings1 >> dot >> pence1;

        cout << "Enter second amount (e.g., £3.2.6): £";
        cin >> pounds2 >> dot >> shillings2 >> dot >> pence2;

        totalPence = pence1 + pence2;
        totalShillings = shillings1 + shillings2 + (totalPence / 12);
        totalPounds = pounds1 + pounds2 + (totalShillings / 20);

        totalPence %= 12;
        totalShillings %= 20;

        cout << "Total is £" << totalPounds << "." << totalShillings << "." << totalPence << endl;

        cout << "Do you wish to continue (y/n)? ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program terminated." << endl;
    return 0;
}
