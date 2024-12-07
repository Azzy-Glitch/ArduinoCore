#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    // connecting our file with hout stream
    ofstream out("sample60.txt");

    // creating a name string variable and filling it with string entered by the user
    string name;
    cout << "Enter your name: ";
    getline(cin, name); // Use getline to read the entire line, including spaces

    // writing a string to the file
    out << name + " is my name.";

    // disconnecting our file
    out.close();

    // connecting our file with hin stream
    ifstream in("sample60.txt");

    // creating a content string variable and filling it with string present there in the text file
    string content;
    getline(in, content); // Use getline to read the entire line from the file
    cout << "The content of the file is: " << content;

    // disconnecting our file
    in.close();
    return 0;
}