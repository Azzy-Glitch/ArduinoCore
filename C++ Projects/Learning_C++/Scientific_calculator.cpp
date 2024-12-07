#include <iostream>
#include <cmath>
#include <stdexcept>

// Utility function to get two numbers from the user
void getNumbers(double &num1, double &num2)
{
    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;
}

// Utility function to display results
void displayResults(const std::string &operation, double result)
{
    std::cout << operation << ": " << result << std::endl;
}

class SimpleCalculator
{
public:
    void calculate()
    {
        double num1, num2;
        getNumbers(num1, num2);
        displayResults("Addition", num1 + num2);
        displayResults("Subtraction", num1 - num2);
        displayResults("Multiplication", num1 * num2);
        if (num2 != 0)
        {
            displayResults("Division", num1 / num2);
        }
        else
        {
            throw std::runtime_error("Error: Division by zero");
        }
    }
};

class ScientificCalculator
{
public:
    void calculate()
    {
        double num1, num2;
        getNumbers(num1, num2);
        displayResults("Power", pow(num1, num2));
        if (num1 >= 0)
        {
            displayResults("Square Root", sqrt(num1));
        }
        else
        {
            throw std::runtime_error("Error: Square root of negative number");
        }
        if (num1 > 0)
        {
            displayResults("Logarithm", log(num1));
        }
        else
        {
            throw std::runtime_error("Error: Logarithm of non-positive number");
        }
        displayResults("Exponential", exp(num1));
    }
};

class HybridCalculator : public SimpleCalculator, public ScientificCalculator
{
public:
    void calculate()
    {
        try
        {
            SimpleCalculator::calculate();
            ScientificCalculator::calculate();
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
};

int main()
{
    HybridCalculator calculator;
    calculator.calculate();
    return 0;
}