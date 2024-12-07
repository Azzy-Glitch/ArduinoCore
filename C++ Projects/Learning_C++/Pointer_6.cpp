#include <iostream>
#include <string>

class Person
{
public:
    std::string name;
    int age;

    Person &setName(std::string name)
    {
        this->name = name;
        return *this; // Return the current object
    }

    Person &setAge(int age)
    {
        this->age = age;
        return *this; // Return the current object
    }

    void display()
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main()
{
    Person person;

    person.setName("John").setAge(25).display();

    return 0;
}