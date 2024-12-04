#include <iostream>
#include <string>
using namespace std;

class Books
{
    string *author, *title, *publisher;
    float *price;
    int *stock;

public:
    Books(string a, string t, string p, float pr, int s)
    {
        author = new string(a);
        title = new string(t);
        publisher = new string(p);
        price = new float(pr);
        stock = new int(s);
    }

    void display()
    {
        cout << "Author: " << *author << "\nTitle: " << *title
             << "\nPublisher: " << *publisher << "\nPrice: " << *price
             << "\nStock: " << *stock << endl;
    }

    bool search(string t, string a)
    {
        return (*title == t && *author == a);
    }

    void sellBook(int copies)
    {
        cout << endl;
        if (copies <= *stock)
        {
            cout << "Total cost: Rs. " << copies * (*price) << endl;
            *stock -= copies;
        }
        else
        {
            cout << "Required copies not in stock.\n";
        }
    }

    ~Books()
    {
        delete author;
        delete title;
        delete publisher;
        delete price;
        delete stock;
    }
};

int main()
{
    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    cin.ignore();

    Books *inventory[n];

    for (int i = 0; i < n; i++)
    {
        string author, title, publisher;
        float price;
        int stock;

        cout << "\nEnter details of book " << i + 1 << ":\n";
        cout << "Author: ";
        getline(cin, author);
        cout << "Title: ";
        getline(cin, title);
        cout << "Publisher: ";
        getline(cin, publisher);
        cout << "Price: ";
        cin >> price;
        cout << "Stock: ";
        cin >> stock;
        cin.ignore();

        inventory[i] = new Books(author, title, publisher, price, stock);
    }

    string searchTitle, searchAuthor;
    cout << "\nEnter title and author to search: ";
    getline(cin, searchTitle);
    getline(cin, searchAuthor);

    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (inventory[i]->search(searchTitle, searchAuthor))
        {
            found = true;
            inventory[i]->display();
            int copies;
            cout << "Enter number of copies: ";
            cin >> copies;
            inventory[i]->sellBook(copies);
            break;
        }
    }

    if (!found)
    {
        cout << "Book not available.\n";
    }

    for (int i = 0; i < n; i++)
    {
        delete inventory[i];
    }

    return 0;
}
