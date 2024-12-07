#include <iostream>
using namespace std;

bool isValidPassword(char password[], int length)
{
    if (length < 6)
    {
        cout << "Password must be at least 6 characters long.\n";
        return false;
    }

    bool hasUpper = false, hasLower = false, hasDigit = false;

    for (int i = 0; i < length; i++)
    {
        char ch = password[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            hasUpper = true;
        }
        if (ch >= 'a' && ch <= 'z')
        {
            hasLower = true;
        }
        if (ch >= '0' && ch <= '9')
        {
            hasDigit = true;
        }
    }

    if (!hasUpper)
    {
        cout << "Password must contain at least one uppercase letter.\n";
        return false;
    }
    if (!hasLower)
    {
        cout << "Password must contain at least one lowercase letter.\n";
        return false;
    }
    if (!hasDigit)
    {
        cout << "Password must contain at least one digit.\n";
        return false;
    }

    return true;
}

int main()
{
    char password[100]; 
    int length = 0;

    cout << "Enter a password: ";
    cin >> password;

    
    for (length = 0; password[length] != '\0'; length++);

    if (isValidPassword(password, length))
    {
        cout << "Password is valid.\n";
    }
    else
    {
        cout << "Password is invalid.\n";
    }

    return 0;
}
