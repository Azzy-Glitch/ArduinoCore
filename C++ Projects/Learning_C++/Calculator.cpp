#include <iostream>
#include <cmath>

using namespace std;

class SimpleCalculator
{
public:
    void add()
    {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        cout << "Addition: " << num1 + num2 << endl;
    }

    void subtract()
    {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        cout << "Subtraction: " << num1 - num2 << endl;
    }

    void multiply()
    {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        cout << "Multiplication: " << num1 * num2 << endl;
    }

    void divide()
    {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        if (num2 != 0)
        {
            cout << "Division: " << num1 / num2 << endl;
        }
        else
        {
            cout << "Error: Division by zero" << endl;
        }
    }
};

class ScientificCalculator
{
public:
    void power()
    {
        double num1, num2;
        cout << "Enter the base number: ";
        cin >> num1;
        cout << "Enter the exponent: ";
        cin >> num2;
        cout << "Power: " << pow(num1, num2) << endl;
    }

    void squareRoot()
    {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        cout << "Square Root: " << sqrt(num) << endl;
    }

    void logarithm()
    {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        cout << "Logarithm: " << log(num) << endl;
    }

    void exponential()
    {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        cout << "Exponential: " << exp(num) << endl;
    }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{
public:
    void calculate()
    {
        add();
        subtract();
        multiply();
        divide();
        power();
        squareRoot();
        logarithm();
        exponential();
    }
};

int main()
{
    HybridCalculator calculator;
    calculator.calculate();
    return 0;
}