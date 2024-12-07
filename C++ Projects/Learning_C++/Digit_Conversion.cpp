#include <iostream>
#include <conio.h> 
using namespace std;

int main()
{
    int i;
    char ch;
    long n = 0;

    cout << "Enter a number (up to 6 digits): ";

    for (i = 1; i <= 6; i++)
    {
        ch = getche(); 

        if (ch >= '0' && ch <= '9')
        {
            n = n * 10 + (ch - '0'); 
        }
        else
        {
            break; 
        }
    }

    cout << "\nNumber is: " << n << endl;
    return 0;
}
