#include <iostream>
#include <vector>

using namespace std;

template <class T>
void display(vector<T> &v)
{
    cout << " Displaying this Vector " << endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
}

int main()
{
    vector<int> vec1;
    // 4-Element Vector
    vector<char> vec2(4);
    vector<char> vec3(vec2);
    vector<int> vec4(6, 3);

    // int element, size;

    // cout << "Enter the Size of Vector " << endl;
    // cin >> size;

    // while (size <= 0)
    // {
    //     cout << "Please enter a positive number " << endl;
    //     cin >> size;
    // }

    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter an Element " << endl;
    //     cin >> element;
    //     vec1.push_back(element);
    // }

    //  display(vec1);
    //  vec2.push_back('F');
    //  display(vec2);
    //  display(vec3);
    //  display(vec4);
    //  vec1.pop_back();

    // display(vec1);
    // vector<int>::iterator iter = vec1.begin();
    // vec1.insert(iter + 1 ,5, 2917);

    // display(vec1);

    return 0;
}