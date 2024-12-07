#include <iostream>

using namespace std;

template <class T1 = int, class T2 = char, class T3 = char>
class F
{
public:
    T1 a;
    T2 b;
    T3 c;
    F(T1 x, T2 y, T3 z)
    {
        a = x;
        b = y;
        c = z;
    }
    void Display()
    {
        cout << "The value of a is " << a << endl;
        cout << "The value of b is " << b << endl;
        cout << "The value of c is " << c << endl;
    }
};
int main()
{
    F<> f(2917, 'A', 'F');
    f.Display();

    cout << endl;

    F<float, char, char> a(1.6, 'F', 'W');
    a.Display();

    return 0;
}