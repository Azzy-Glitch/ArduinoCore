#include <iostream>
using namespace std;

int main()
{
    // Explicit typecasting
    int a = 10;
    float b = 20.5;

    cout << "Before typecasting:" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    // Implicit typecasting
    a = b;

    cout << "After implicit typecasting:" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    // Explicit typecasting
    b = (float)a;

    cout << "After explicit typecasting:" << endl;
    cout << "Value of a: " << a << endl;
    cout << "Value of b: " << b << endl;

    // C-style typecasting
    b = (float)a;

    cout << "C-style typecasting:" << endl;
    cout << "Value of b: " << b << endl;

    // Function-style typecasting
    b = float(a);

    cout << "Function-style typecasting:" << endl;
    cout << "Value of b: " << b << endl;

    // C++ style typecasting
    b = static_cast<float>(a);

    cout << "C++ style typecasting:" << endl;
    cout << "Value of b: " << b << endl;

    return 0;
}