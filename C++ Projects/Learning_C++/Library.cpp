
#include <iostream>
#include <vector>

using namespace std;

class library
{

    vector<int> Book;
    vector<string> Title;
    vector<string> Author;

public:
    void add_book()
    {
        int id;
        string title, author;

        cout << "Enter the ID of the book: ";
        cin >> id;

        cout << "Enter the title of the book: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter the author of the book: ";
        getline(cin, author);

        cout << "Books in the library:\n";

        Book.push_back(id);
        Title.push_back(title);
        Author.push_back(author);
    }
    void display_book()
    {
        for (size_t i = 0; i < Book.size(); i++)
        {
            cout << "Book ID: " << Book[i] << ", Title: " << Title[i] << ", Author: " << Author[i] << endl;
        }
    }
};

int main()
{
    library a;

    int N_of_books;
    cout << "Enter number of Books: " << endl;
    cin >> N_of_books;

    for (int i = 1; i <= N_of_books; i++)
    {
        a.add_book();
    }
    a.display_book();

    return 0;
}
