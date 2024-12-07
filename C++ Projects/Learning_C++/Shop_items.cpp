#include <iostream>

using namespace std;

class shop
{
    int item_id[100];
    int item_price[100];
    int counter;

public:
    void init_counter(void) { counter = 0; }
    void set_price(void);
    void display_price(void);
};

void shop ::set_price(void)
{
    cout << "ENTER ID OF YOUR ITEM " << counter + 1 << endl;
    cin >> item_id[counter];
    cout << "ENTER PRICE OF YOUR ITEM" << endl;
    cin >> item_price[counter];
    counter++;
}

void shop ::display_price(void)
{
    for (int i = 0; i < counter; i++)
    {
        cout << "THE PRICE OF THE ITEM WITH ID " << item_id[i] << " IS " << item_price[i] << endl;
    }
}

int main()
{
    shop a;
    a.init_counter();

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