#include <iostream>

using namespace std;

int main()
{
    int a = 7, b = 9;
    if ((a != b) && (a >= 7 || b < 9))
    {
        cout << a++ << "!" << --b << endl;
        b = a++;
        cout << --a << endl;
        cout << b-- << endl;
        cout << "hello\b world" << endl;
        cout << "hello \r world" << endl;
    }
    else
    {
        cout << "hello\b world" << endl;
        cout << "hello \r world" << endl;
    }
    return 0;
}
