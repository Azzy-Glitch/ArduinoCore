#include <iostream>
#include <vector>

using namespace std;

class Employee
{
    int id = 0;

public:
    static int count;
    void set_data(void)
    {
        cout << "ENTER ID PLEASE" << endl;
        cin >> id;
        count++;
    }

    void get_data(void) const
    {
        cout << "THE ID OF THE EMPLOYEE IS " << id <<endl;
    }
    
    int get_id() const
    {
        return id;
    }
};

int Employee::count = 0;

int main()
{
    vector<Employee> employees;

    int N_OF_Emp;
    cout << "ENTER NUMBER OF ENTRIES " << endl;
    cin >> N_OF_Emp;

    for (int i = 0; i < N_OF_Emp; i++)
    {
        Employee emp;
        emp.set_data();
        employees.push_back(emp);
    }

    for (const auto& emp : employees)
    {
        emp.get_data();
    }

    cout << "THE TOTAL NUMBER OF EMPLOYEES IS " << Employee::count << endl;
    cout << "ALL EMPLOYEE IDS:" << endl;
    for (const auto& emp : employees)
    {
        cout << emp.get_id() << endl;
    }

    return 0;
}
