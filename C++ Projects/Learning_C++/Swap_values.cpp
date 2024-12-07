#include <iostream>

using namespace std;

class c2;

class c1
{
    int value1;

public:
    void data(int a)
    {
        value1 = a;
    }
    void display(void)
    {
        cout << value1 << endl;
    }
    friend void swap(c1 &, c2 &);
};

class c2
{
    int value2;

public:
    void data(int a)
    {
        value2 = a;
    }
    void display(void)
    {
        cout << value2 << endl;
    }
    friend void swap(c1 &, c2 &);
};

void swap(c1 &x, c2 &y)
{
    int temporary = x.value1;
    x.value1 = y.value2;
    y.value2 = temporary;
}

int main()
{
    c1 a;
    a.data(98);

    c2 b;
    b.data(75);

    swap(a, b);
    cout << "After swaping the Values of both classes " << endl;

    a.display();
    b.display();

    return 0;
}