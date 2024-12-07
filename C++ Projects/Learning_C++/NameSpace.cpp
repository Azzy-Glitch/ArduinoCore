#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace myNamespace
{
    int myVar = 42;

    void display()
    {
        cout << "Value of myVar: " << myVar << endl;
    }

    int add(int a, int b)
    {
        return a + b;
    }

    class MyClass
    {
    private:
        string name;
        int value;

    public:
        MyClass(string n, int v) : name(n), value(v) {}

        void showDetails()
        {
            cout << "Name: " << name << ", Value: " << value << endl;
        }
    };

    namespace Utilities
    {

        int findMax(const vector<int> &vec)
        {
            int max = vec[0];
            for (int i = 1; i < vec.size(); ++i)
            {
                if (vec[i] > max)
                {
                    max = vec[i];
                }
            }
            return max;
        }

        void printVector(const vector<int> &vec)
        {
            for (int i = 0; i < vec.size(); ++i)
            {
                cout << vec[i] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{

    myNamespace::myVar = 100;
    myNamespace::display();

    int sum = myNamespace::add(10, 20);
    cout << "Sum: " << sum << endl;

    myNamespace::MyClass obj("TestObject", 123);
    obj.showDetails();

    vector<int> numbers = {1, 2, 3, 4, 5};
    myNamespace::Utilities::printVector(numbers);
    int maxNum = myNamespace::Utilities::findMax(numbers);
    cout << "Max number: " << maxNum << endl;

    return 0;
}
