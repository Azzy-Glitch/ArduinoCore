
#include <iostream>
using namespace std;

int main()
{
    int num, reverse = 0, sum = 0, remainder;

    cout << "Enter a number: ";
    cin >> num;

    int originalNum = num;

    while (num != 0)
    {
        remainder = num % 10;
        sum += remainder;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }

    cout << "Original Number: " << originalNum << endl;
    cout << "Reversed Number: " << reverse << endl;
    cout << "Sum of Digits: " << sum << endl;

    return 0;
}
