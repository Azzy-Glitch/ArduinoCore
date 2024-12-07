#include <iostream>

using namespace std;

class complex
{
    int a, b;

public:
    complex(int x, int y) : a(x), b(y) {}

    complex(int x) : a(x), b(0) {}

    void Print_Numbers()
    {
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    complex c(4, 9);
    c.Print_Numbers();

    complex c_1(7);
    c_1.Print_Numbers();

    return 0;
}