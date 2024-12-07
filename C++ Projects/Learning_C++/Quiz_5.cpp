#include <iostream>
using namespace std;

int main()
{
    float x, y;

    cout << "Enter the x coordinate: ";
    cin >> x;
    cout << "Enter the y coordinate: ";
    cin >> y;

    if (x == 0 && y == 0)
    {
        cout << "The point is at the origin." << endl;
    }
    else if (x == 0)
    {
        cout << "The point lies on the y-axis." << endl;
    }
    else if (y == 0)
    {
        cout << "The point lies on the x-axis." << endl;
    }
    else if (x > 0 && y > 0)
    {
        cout << "The point lies in Quadrant I." << endl;
    }
    else if (x < 0 && y > 0)
    {
        cout << "The point lies in Quadrant II." << endl;
    }
    else if (x < 0 && y < 0)
    {
        cout << "The point lies in Quadrant III." << endl;
    }
    else if (x > 0 && y < 0)
    {
        cout << "The point lies in Quadrant IV." << endl;
    }

    return 0;
}
