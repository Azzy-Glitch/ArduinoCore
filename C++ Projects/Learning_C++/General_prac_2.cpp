#include <iostream>

using namespace std;

int main()
{
    
    const int x = 10;
    cout << x << "\n";
    int y = x;
    y += 10;
    cout << y << "\n";
    y--;
    cout << y << "\n";

    return 0;
}