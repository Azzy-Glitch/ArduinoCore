#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cout << "Enter first fraction; " << endl;
    cin >> a >> b;

    cout << "Enter second fraction; " << endl;
    cin >> c >> d;

    cout << "The sum of the two fractions is " << (a * d + b * c) / (b * d) << endl;
    return 0;
}