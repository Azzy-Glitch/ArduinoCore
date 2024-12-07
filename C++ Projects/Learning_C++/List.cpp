#include <iostream>
#include <list>

using namespace std;

void display(list<int> &lst)
{
    list<int>::iterator it;
    for (it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> list_1;

    list_1.push_back(5);
    list_1.push_back(6);
    list_1.push_back(7);
    list_1.push_back(8);
    list_1.push_back(9);

    display(list_1);

    // Methods to Remove elements from yhe list
    // list_1.pop_back();
    // list_1.pop_front();
    // list_1.remove(6);
    // list_1.clear();
    // list_1.sort();

    // display(list_1);

    list<int> list_2(3);
    list<int>::iterator iter;
    iter = list_2.begin();

    *iter = 1;
    iter++;

    *iter = 2;
    iter++;

    *iter = 3;
    iter++;

    display(list_2);

    list_1.merge(list_2);
    list_1.sort();

    cout << "After merging both list " << endl;

    display(list_1);

    return 0;
}