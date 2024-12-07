#include <iostream>
#include <cmath>
using namespace std;

class Point {
    int x, y;
    friend void calculateDistance(Point, Point);

public:
    Point(int a, int b) : x(a), y(b) {}

    void displayPoint() const {
        cout << "The Point is: (" << x << " , " << y << ")" << endl;
    }
};

void calculateDistance(Point point1, Point point2) {
    int x_diff = point2.x - point1.x;
    int y_diff = point2.y - point1.y;
    double distance = sqrt(pow(x_diff, 2) + pow(y_diff, 2));
    cout << "The distance between the points is: " << distance << endl;
}

int main() {
    int x1, y1, x2, y2;

    cout << "Enter the coordinates of the first point (x y): ";
    cin >> x1 >> y1;
    Point point1(x1, y1);

    cout << "Enter the coordinates of the second point (x y): ";
    cin >> x2 >> y2;
    Point point2(x2, y2);

    point1.displayPoint();
    point2.displayPoint();

    calculateDistance(point1, point2);

    return 0;
}
