#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    if (a + b > c && a + c > b && b + c > a) {
        cout << "The numbers can form a valid triangle." << endl;
    } else {
        cout << "The numbers cannot form a valid triangle." << endl;
    }

    return 0;
}