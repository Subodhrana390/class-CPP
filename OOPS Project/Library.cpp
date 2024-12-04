#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Book
{
public:
    string title;
    string author;
    string ISBN;
    bool isCheckedOut;

    Book(string t, string a, string isbn)
        : title(t), author(a), ISBN(isbn), isCheckedOut(false) {}

    // Displays book details
    void displayDetails()
    {
        cout << "Title: " << title << ", Author: " << author
             << ", ISBN: " << ISBN << ", Status: "
             << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    // Checks out the book if it's available
    bool checkOut()
    {
        if (isCheckedOut)
        {
            return false;
        }
        isCheckedOut = true;
        return true;
    }

    // Returns the book if it's checked out
    bool returnBook()
    {
        if (!isCheckedOut)
        {
            return false;
        }
        isCheckedOut = false;
        return true;
    }

    string getTitle() { return title; }
    bool isAvailable() { return !isCheckedOut; }
};

class User
{
public:
    string username;
    string password;

    User(string user, string pass)
        : username(user), password(pass) {}
};

class UserManager
{
private:
    vector<User> users;

public:
    // Loads users from a file
    void loadUsers(string filename)
    {
        ifstream inFile(filename);
        string line;
        while (getline(inFile, line))
        {
            size_t separator = line.find(',');
            string user = line.substr(0, separator);
            string pass = line.substr(separator + 1);
            users.emplace_back(user, pass);
        }
    }

    // Authenticates a user by matching username and password
    bool authenticate(string username, string password)
    {
        for (auto &user : users)
        {
            if (user.username == username && user.password == password)
            {
                return true;
            }
        }
        return false;
    }
};

class Library
{
private:
    vector<Book> books;

public:
    // Adds a new book to the library
    void addBook(Book book)
    {
        books.push_back(book);
    }

    // Displays all available books
    void displayAvailableBooks()
    {
        for (auto &book : books)
        {
            if (book.isAvailable())
            {
                book.displayDetails();
            }
        }
    }

    // Searches for a book by title
    Book *searchBook(string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title)
            {
                return &book;
            }
        }
        return nullptr;
    }

    // Checks out a book if it’s available
    bool checkout(string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title && book.isAvailable())
            {
                return book.checkOut();
            }
        }
        return false;
    }

    // Returns a book if it’s checked out
    bool returnBook(string &title)
    {
        for (auto &book : books)
        {
            if (book.getTitle() == title && !book.isAvailable())
            {
                return book.returnBook();
            }
        }
        return false;
    }

    // Saves the library data to a file
    void saveToFile(string filename)
    {
        ofstream outFile(filename);
        if (outFile.is_open())
        {
            for (auto &book : books)
            {
                outFile << book.getTitle() << ","
                        << book.author << ","
                        << book.ISBN << ","
                        << (book.isAvailable() ? "0" : "1") << "\n";
            }
            outFile.close();
        }
        else
        {
            cerr << "Could not open file for writing." << endl;
        }
    }

    // Loads library data from a file
    void loadFromFile(string filename)
    {
        ifstream inFile(filename);
        string line;
        while (getline(inFile, line))
        {
            istringstream ss(line);
            string title, author, isbn, isCheckedOut;
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, isbn, ',');
            getline(ss, isCheckedOut, ',');
            Book book(title, author, isbn);
            if (isCheckedOut == "1")
            {
                book.checkOut();
            }
            books.push_back(book);
        }
        inFile.close();
    }
};

int main()
{
    Library library;
    UserManager userManager;

    // Load users and books from files
    userManager.loadUsers("users.txt");
    library.loadFromFile("books.txt");

    // User authentication
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (!userManager.authenticate(username, password))
    {
        cerr << "Authentication failed!" << endl;
        return 1;
    }

    int choice;
    do
    {
        cout << "\n1. Add Book\n2. View Available Books\n3. Check Out Book\n4. Return Book\n5. Search Book\n6. Save\n7. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Adding a book
            string title, author, isbn;
            cout << "Enter title, author, and ISBN: ";
            cin.ignore();
            getline(cin, title);
            getline(cin, author);
            getline(cin, isbn);
            library.addBook(Book(title, author, isbn));
            break;
        }
        case 2:
            // Display available books
            library.displayAvailableBooks();
            break;
        case 3:
        {
            // Check out a book
            string title;
            cout << "Enter title of the book to check out: ";
            cin.ignore();
            getline(cin, title);
            if (library.checkout(title))
            {
                cout << title << " has been checked out." << endl;
            }
            else
            {
                cout << title << " could not be checked out." << endl;
            }
            break;
        }
        case 4:
        {
            // Return a book
            string title;
            cout << "Enter title of the book to return: ";
            cin.ignore();
            getline(cin, title);
            if (library.returnBook(title))
            {
                cout << title << " has been returned." << endl;
            }
            else
            {
                cout << title << " could not be returned." << endl;
            }
            break;
        }
        case 5:
        {
            // Search for a book
            string title;
            cout << "Enter title of the book to search for: ";
            cin.ignore();
            getline(cin, title);
            Book *book = library.searchBook(title);
            if (book)
            {
                book->displayDetails();
            }
            else
            {
                cout << "Book not found." << endl;
            }
            break;
        }
        case 6:
            // Save books to file
            library.saveToFile("books.txt");
            cout << "Books saved to file." << endl;
            break;
        case 7:
            // Exit
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
