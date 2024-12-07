#include <iostream>

using namespace std;

int main() {
  int pounds, shillings, pence;

  cout << "Enter pounds: ";
  cin >> pounds;

  cout << "Enter shillings: ";
  cin >> shillings;

  cout << "Enter pence: ";
  cin >> pence;

  double decimal_Pounds = pounds + (shillings / 20.0) + (pence / 240.0);

  cout << "Decimal pounds = £" << decimal_Pounds << endl;

  return 0;
}