#include <iostream>

using namespace std;

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
    friend complex sum_numbers(complex, complex);
};

// Friend function to add two complex numbers

complex sum_numbers(complex o1, complex o2)
{
    complex o3;
    o3.set_numbers((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}
int main()
{
    complex c1, c2, sum;
    c1.set_numbers(1, 4);
    c2.set_numbers(5, 8);

    c1.Print_Numbers();
    c2.Print_Numbers();

    sum = sum_numbers(c1, c2);
    sum.Print_Numbers();

    return 0;
}