#include <iostream>

using namespace std;

class Y;

class X
{
    int data;

public:
    void set_value(int value)
    {
        data = value;
    }
    friend void add(X, Y);
};

class Y
{
    int num;

public:
    void set_value(int value)
    {
        num = value;
    }
    friend void add(X, Y);
};
void add(X o1, Y o2)
{
    cout << "Displaying data of Both Classes X and Y is " << o1.data + o2.num <<endl;
}
int main()
{
    X a;
    a.set_value(9);

    Y b;
    b.set_value(5);

    add(a, b);

    return 0;
}