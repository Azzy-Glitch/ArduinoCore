#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int width = 15;

    cout << "Protcity" << setw(width) << setfill('.') << 2425785 << endl;

    return 0;
}