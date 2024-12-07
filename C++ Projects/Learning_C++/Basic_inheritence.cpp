
#include <iostream>

using namespace std;

// Base Class
class Employee
{
public:
    int id;
    float salary;

    Employee(int inpId)
    {
        id = inpId;
        salary = 34.0;
    }
    
    Employee() {}
};

// Creating a Programmer class derived from Employee Base class
class Programmer : public Employee
{
public:
    int languageCode;

    Programmer(int inpId)
    {
        id = inpId;
        languageCode = 9;
    }

    void getData()
    {
        cout << id << endl;
    }
};

int main()
{
    Employee Azzy(1), Jazzy(2);

    cout << Azzy.salary << endl;
    cout << Jazzy.salary << endl;

    Programmer skillF(10);

    cout << skillF.languageCode << endl;
    cout << skillF.id << endl;

    skillF.getData();

    return 0;
}
