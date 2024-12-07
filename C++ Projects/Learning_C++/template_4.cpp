#include <iostream>

using namespace std;

template <class T>
class Azzy
{
public:
    T data;
    Azzy(T a)
    {
        data = a;
    }
    void display();
};

template <class T>
void Azzy<T>::display()
{
    cout << data << endl;
}

void func(int a)
{
    cout << "I am first function() " << a << endl;
}

template <class T>
void func(T a)
{
    cout << "I am templatised function() " << a << endl;
}

int main()
{
    Azzy<char> a('F');
    cout << a.data << endl;
    a.display();

    func(4);
    func('F');
    return 0;
}
