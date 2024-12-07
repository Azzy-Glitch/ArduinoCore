#include <iostream>
using namespace std;

int main() {
    int year;

    cout << "Enter a year: ";
    cin >> year;

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                cout << "The year is a leap year.\n";
            } else {
                cout << "The year is not a leap year.\n";
            }
        } else {
            cout << "The year is a leap year.\n";
        }
    } else {
        cout << "The year is not a leap year.\n";
    }

    return 0;
}