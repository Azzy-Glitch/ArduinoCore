#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double decimal_pounds;

    cout << "Enter decimal pounds: ";
    cin >> decimal_pounds;

    int pounds = decimal_pounds;
    int shillings = (decimal_pounds - pounds) * 20;
    int pence = (decimal_pounds - pounds - (shillings / 20.0)) * 240;

    cout << "Old British currency: " << pounds << ". " << shillings << ". " << pence << endl;

    return 0;
}