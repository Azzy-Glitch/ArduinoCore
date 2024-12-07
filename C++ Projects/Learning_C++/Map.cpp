#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{

    // Map is an associative array
    map<string, int> marksMap;
    marksMap["AZZY"] = 58;
    marksMap["Saliii"] = 57;
    marksMap["Badmoosh"] = 78;
    marksMap["Loniii"] = 65;
    marksMap["Phupo"] = 53;

    marksMap.insert({{"Sigma ", 0}, {"Muniiiii", 7}});
    map<string, int>::iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << "\n";
    }

    cout << "The size of the Map is " << marksMap.size() << endl;
    cout << "The Maxsize of the Map is " << marksMap.max_size() << endl;
    cout << "The return vlue of empty is " << marksMap.empty() << endl;

    return 0;
}
