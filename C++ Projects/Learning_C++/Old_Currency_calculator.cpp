#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int pounds1, shillings1, pence1;
    int pounds2, shillings2, pence2;

    int resultPounds, resultShillings, resultPence;

    double multiplier;  
    char operation;

    cout << "Enter the first amount (pounds shillings pence): ";
    cin >> pounds1 >> shillings1 >> pence1;

    shillings1 += pence1 / 12;
    pence1 %= 12;
    pounds1 += shillings1 / 20;
    shillings1 %= 20;

    cout << "Enter an operation (+, -, *): ";
    cin >> operation;

    if (operation == '+' || operation == '-') {

        cout << "Enter the second amount (pounds shillings pence): ";
        cin >> pounds2 >> shillings2 >> pence2;

        shillings2 += pence2 / 12;
        pence2 %= 12;
        pounds2 += shillings2 / 20;
        shillings2 %= 20;
        
        if (operation == '+') {

            resultPounds = pounds1 + pounds2;
            resultShillings = shillings1 + shillings2;
            resultPence = pence1 + pence2;

            resultShillings += resultPence / 12;
            resultPence %= 12;
            resultPounds += resultShillings / 20;
            resultShillings %= 20;
        } else {

            int totalPence1 = (pounds1 * 240) + (shillings1 * 12) + pence1;
            int totalPence2 = (pounds2 * 240) + (shillings2 * 12) + pence2;

            int diffPence = totalPence1 - totalPence2;

            resultPounds = diffPence / 240;
            resultShillings = (diffPence % 240) / 12;
            resultPence = diffPence % 12;
        }

    } else if (operation == '*') {

        cout << "Enter a multiplier: ";
        cin >> multiplier;

        int totalPence = (pounds1 * 240) + (shillings1 * 12) + pence1;
        totalPence = round(totalPence * multiplier); 

        resultPounds = totalPence / 240;
        resultShillings = (totalPence % 240) / 12;
        resultPence = totalPence % 12;

    } else {
        cout << "Invalid operation." << endl;
        return 1;
    }

    cout << "Result: £" << resultPounds << "." << resultShillings << "." << resultPence << endl;

    return 0;
}
