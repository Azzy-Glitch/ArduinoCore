#include <iostream>
#include <iomanip>
using namespace std;

void generateMultiplesTable(int number) {
    const int columns = 10;
    const int rows = 20;
    int multiples[rows * columns];

    for (int i = 0; i < rows * columns; ++i) {
        multiples[i] = number * (i + 1);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {

            cout << setw(4) << multiples[i * columns + j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    cout << endl;
    generateMultiplesTable(number);

    return 0;
}