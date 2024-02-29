/*
TASK 5 - LIBRARY MANAGEMENT TOOL
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Book
{   public:
    string id;
    string title;
    string author;
    string ISBN;
    bool available;

public:
    
    Book() : available(true) {}

    void inputBookInfo()
    {
        cout << "Enter Book ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
        cout << "Enter Book ISBN: ";
        getline(cin, ISBN);
    }

    void displayBookInfo() const
    {
        cout << "Book ID: " << id << "\nTitle: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN
             << "\nAvailability: " << (available ? "Available" : "Not Available") << endl;
    }

    const string &getISBN() const
    {
        return ISBN;
    }

    bool isAvailable() const
    {
        return available;
    }

    void setAvailability(bool status)
    {
        available = status;
    }
};

class LibrarySystem
{
    vector<Book> books;

public:
    void addBook();
    void showAllBooks();
    void searchBooks();
    void checkoutBook();
    void returnBook();
    void calculateFine();
    void displayMenu();
};

void LibrarySystem::addBook()
{
    Book newBook;
    newBook.inputBookInfo();
    books.push_back(newBook);

    ofstream file("bookData.txt", ios::app);
    file << newBook.getISBN() << "*" << newBook.title << "*" << newBook.author << "*" << (newBook.isAvailable() ? "true" : "false") << endl;
    file.close();

    cout << "Book added successfully!" << endl;
}

void LibrarySystem::showAllBooks()
{
    cout << "\nList of All Books:\n";
    for (const auto &book : books)
    {
        book.displayBookInfo();
        cout << "------------------------\n";
    }
}

void LibrarySystem::searchBooks()
{
    string searchKey;
    cout << "Enter the title, author, or ISBN to search for a book: ";
    cin.ignore();
    getline(cin, searchKey);

    cout << "\nSearch Results:\n";
    for (const auto &book : books)
    {
        if (book.getISBN().find(searchKey) != string::npos ||
            book.title.find(searchKey) != string::npos ||
            book.author.find(searchKey) != string::npos)
        {
            book.displayBookInfo();
            cout << "------------------------\n";
        }
    }
}

void LibrarySystem::checkoutBook()
{
    string ISBN;
    cout << "Enter the ISBN of the book to be checked out: ";
    cin.ignore();
    getline(cin, ISBN);

    auto bookIt = find_if(books.begin(), books.end(), [&ISBN](const Book &book)
                          { return book.getISBN() == ISBN && book.isAvailable(); });

    if (bookIt != books.end())
    {
        bookIt->setAvailability(false);
        cout << "Book checked out successfully!" << endl;
    }
    else
    {
        cout << "Book not available for checkout." << endl;
    }
}

void LibrarySystem::returnBook()
{
    string ISBN;
    cout << "Enter the ISBN of the book to be returned: ";
    cin.ignore();
    getline(cin, ISBN);

    auto bookIt = find_if(books.begin(), books.end(), [&ISBN](const Book &book)
                          { return book.getISBN() == ISBN && !book.isAvailable(); });

    if (bookIt != books.end())
    {
        bookIt->setAvailability(true);
        cout << "Book returned successfully!" << endl;
    }
    else
    {
        cout << "Invalid ISBN or book already returned." << endl;
    }
}

void LibrarySystem::calculateFine()
{
    // Implement fine calculation based on the due date and return date (exercise for improvement)
    cout << "Fine calculation not implemented in this version." << endl;
}

void LibrarySystem::displayMenu()
{
    char choice;
    do
    {
        cout << "\nMenu:\n"
             << "1. Add Book\n"
             << "2. Show All Books\n"
             << "3. Search Books\n"
             << "4. Checkout Book\n"
             << "5. Return Book\n"
             << "6. Calculate Fine\n"
             << "7. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            addBook();
            break;
        case '2':
            showAllBooks();
            break;
        case '3':
            searchBooks();
            break;
        case '4':
            checkoutBook();
            break;
        case '5':
            returnBook();
            break;
        case '6':
            calculateFine();
            break;
        case '7':
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != '7');
}

int main()
{
    LibrarySystem library;
    library.displayMenu();

    return 0;
}
