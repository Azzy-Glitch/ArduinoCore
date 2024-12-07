#include <iostream>
#include <vector>

using namespace std;

class shop
{
    vector<int> item_id;
    vector<int> item_price;

public:
    void set_price(void);
    void display_price(void) const;
};

void shop ::set_price(void)
{
    int id, price;
    cout << "ENTER ID OF YOUR ITEM " << endl;
    cin >> id;
    cout << "ENTER PRICE OF YOUR ITEM" << endl;
    cin >> price;

    item_id.push_back(id);
    item_price.push_back(price);
}

void shop ::display_price(void) const
{
    for (size_t i = 0; i < item_id.size(); i++)
    {
        cout << "THE PRICE OF THE ITEM WITH ID " << item_id[i]
         << " IS " << item_price[i] << endl;
    }
}

int main()
{
    shop a;

    int numItems;

    cout << "Enter the number of items: " << endl;

    cin >> numItems;

    for (int i = 0; i < numItems; i++)
    {
        a.set_price();
    }

    a.display_price();

    return 0;
}
