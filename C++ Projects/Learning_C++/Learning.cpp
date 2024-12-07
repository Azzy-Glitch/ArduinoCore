#include <iostream>

using namespace std;

class complex
{
    int a, b;

public:
    complex(void);

    void Print_Numbers()
    {
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }
};

complex::complex(void)
{
    a = 20;
    b = 0;
}
int main()
{
    complex c;
    c.Print_Numbers();
    return 0;
}