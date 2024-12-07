#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter number 1: ";
    cin >> a;

    cout << "Enter number 2: ";
    cin >> b;

    cout << "Enter number 3: ";
    cin >> c;

    int min_num = a, max_num = a;

    if (b < min_num)
        min_num = b;
    if (c < min_num)
        min_num = c;

    if (b > max_num)
        max_num = b;
    if (c > max_num)
        max_num = c;

    cout << "Min number is " << min_num << endl;
    cout << "Max number is " << max_num << endl;

    return 0;
}
