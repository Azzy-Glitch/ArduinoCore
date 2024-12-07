#include <iostream>

using namespace std;

class complex;

class calculator
{
public:
    int Add(int a, int b)
    {
        return (a + b);
    }
    int sum_complex(complex, complex);
};

class complex
{
    int a, b;

public:
    void set_numbers(int n1, int n2)
    {
        a = n1;
        b = n2;
    }
    void Print_Numbers()
    {
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }
    // friend int calculator::sum_complex(complex o1, complex o2);
    friend class calculator;
    // if you want to create many friend functions so simply use friend class method
};

int calculator ::sum_complex(complex o1, complex o2)
{
    return (o1.a + o2.a), (o1.b + o2.b);
}

int main()
{
    complex o1, o2;
    o1.set_numbers(3, 7);
    o2.set_numbers(9, 5);
    calculator a;
    int result = a.sum_complex(o1, o2);
    cout << "The sum of the complex numbers is " << result << endl;
    return 0;
}