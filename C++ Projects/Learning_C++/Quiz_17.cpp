#include <iostream>

using namespace std;

int main()
{
    int i = 4;
    while (i <= 25)
    {
        switch (i)
        {
        case 3:
            i = i + 10;
        case 4:
            i = i + 7;
        case 9:
            ++i;
            break;
        case 12:
            i = i + 5;
        case 19:
            i = i + 2;
            break;
        case 21:
            i = i + 3;
        case 2:
            i = i + 3;
        default:
            i += 5;
            break;
        }
        cout << i << endl;
    }
    return 0;
}
