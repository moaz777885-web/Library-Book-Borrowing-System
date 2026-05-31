#include "Functions.h"

void addBook(LibraryBook books[], int& count)
{
    int id;
    string title;
    string author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    books[count] = LibraryBook(id, title, author);
    count++;

    cout << "Book Added Successfully.\n";
}

void displayBooks(LibraryBook books[], int count)
{
    if (count == 0)
    {
        cout << "No books available.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        books[i].displayBook();
    }
}

void searchBook(LibraryBook books[], int count)
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (books[i].getBookID() == id)
        {
            books[i].displayBook();
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void borrowBookMenu(LibraryBook books[], int count)
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    for (int i = 0; i < count; i++)
    {
        if (books[i].getBookID() == id)
        {
            if (books[i].getBorrowed())
            {
                cout << "Book Already Borrowed.\n";
                return;
            }

            string borrower;
            int days;

            cout << "Enter Borrower Name: ";
            getline(cin, borrower);

            cout << "Enter Days Borrowed: ";
            cin >> days;

            books[i].borrowBook(borrower, days);

            cout << "Book Borrowed Successfully.\n";
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void returnBookMenu(LibraryBook books[], int count)
{
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    for (int i = 0; i < count; i++)
    {
        if (books[i].getBookID() == id)
        {
            books[i].returnBook();
            cout << "Book Returned Successfully.\n";
            return;
        }
    }

    cout << "Book Not Found.\n";
}

void displayOverdueBooks(LibraryBook books[], int count)
{
    bool found = false;

    for (int i = 0; i < count; i++)
    {
        if (books[i].isOverdue())
        {
            books[i].displayBook();
            cout << "Fine: $" << books[i].calculateFine() << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Overdue Books.\n";
    }
}

void calculateTotalFines(LibraryBook books[], int count)
{
    double total = 0;

    for (int i = 0; i < count; i++)
    {
        total += books[i].calculateFine();
    }

    cout << "Total Fine Amount = $" << total << endl;
}
