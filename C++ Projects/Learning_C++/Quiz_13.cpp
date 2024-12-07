#include <iostream>
using namespace std;

int main()
{
    float cgpa;

    // Ask user for CGPA input
    cout << "Enter CGPA: ";
    cin >> cgpa;

    // Validate CGPA range
    if (cgpa < 0 || cgpa > 4)
    {
        cout << "Invalid CGPA. Please enter a value between 0 and 4." << endl;
        return 1;
    }

    // Convert CGPA to an integer scale (0 to 40)
    int gradeRange = static_cast<int>(cgpa * 10); // Scale from 0 to 40

    // Use switch to determine grade based on grade range
    switch (gradeRange)
    {
    case 35 ... 40: 

        cout << "Grade: A" << endl;
        cout << "Remarks: Excellent" << endl;
        break;
    case 25 ... 34: 

        cout << "Grade: B" << endl;
        cout << "Remarks: Good" << endl;
        break;
    case 15 ... 24:

        cout << "Grade: C" << endl;
        cout << "Remarks: Satisfactory" << endl;
        break;
    default: 
        cout << "Grade: F" << endl;
        cout << "Remarks: Fail" << endl;
        break;
    }

    return 0;
}