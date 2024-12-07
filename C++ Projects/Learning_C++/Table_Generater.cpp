#include <iostream>
#include <iomanip>

void generateMultiplesTable(int number)
{
    const int columns = 10;
    const int rows = 20;
    int lineCounter = 0;
    std::string exit;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {

            int multiple = number * (i * columns + j + 1);

            std::cout << std::setw(4) << multiple << " ";
        }
        std::cout << std::endl;

        lineCounter++;
        if (lineCounter == 3)
        {
            std::cout << "Enter yes to Exit: " << std::endl;
            std::cin.ignore();
            std::getline(std::cin, exit);
            if (exit == "yes")
            {
                break;
            }
            lineCounter = 0;
        }
    }
}

int main()
{
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::cout << std::endl;
    generateMultiplesTable(number);

    return 0;
}