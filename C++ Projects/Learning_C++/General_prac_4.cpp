#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char ch;

    cout << "Enter a character: ";
    cin >> ch;

    if (islower(ch))
    {
        cout << ch << " is a lowercase letter.";
    }
    else
    {
        cout << ch << " is not a lowercase letter.";
    }

    return 0;
}