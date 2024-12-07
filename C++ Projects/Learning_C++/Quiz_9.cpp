#include <iostream>

using namespace std;

int main()
{
  int Grade;
  cout << "Enter Grade: " << endl;
  cin >> Grade;
  if (Grade >= 0 || Grade <= 100)
  {
    switch (Grade / 10)
    {
    case 10: // For scores 100
    case 9:  // For scores 90-99
      cout << "Grade: A" << endl;
      break;
    case 8: // For scores 80-89
      cout << "Grade: B" << endl;
      break;
    case 7: // For scores 70-79
      cout << "Grade: C" << endl;
      break;
    case 6: // For scores 60-69
      cout << "Grade: D" << endl;
      break;
    default: // For scores 0-59
      cout << "Grade: F" << endl;
      break;
    }
  }
  else
  {
    cout << "Invalid score! Please enter a score between 0 and 100." << endl;
  }
  return 0;
}