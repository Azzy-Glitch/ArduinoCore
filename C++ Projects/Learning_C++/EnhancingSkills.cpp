#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
    string s;
    void read(void);
    void chk_binary(void);
    void ones_compliment(void);

public:
//     void read(void);
       void display(void);
//     void chk_binary(void);
//     void ones_compliment(void);
};

void binary ::read(void)
{
    cout << "ENTER YOUR NUMBER" << endl;
    cin >> s;
}

void binary ::chk_binary(void)
{
    for (size_t i = 0; i < s.length(); i++)
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "INVALID BINARY NUMBER" << endl;
            exit(0);
        }
}

void binary ::ones_compliment(void)
{
    for (size_t i = 0; i < s.length(); i++)
        if (s.at(i) == '0')
        {
            s.at(i) = '1';
        }
        else
        {
            s.at(i) = '0';
        }
}

void binary ::display(void)
{   read();
    chk_binary();
    ones_compliment();
    cout << "DISPLAYING YOUR BINARY NUMBER" << endl;
    for (size_t i = 0; i < s.length(); i++)
    {
        cout << s.at(i);
    }
    cout << endl;
}

int main()
{
    binary b;

    // b.read();

    // b.chk_binary();

    // b.display();

    // b.ones_compliment();

    b.display();

    return 0;
}
