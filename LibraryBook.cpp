#include "LibraryBook.h"

LibraryBook::LibraryBook()
{
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    borrowed = false;
}

LibraryBook::LibraryBook(int id, string t, string a)
{
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    borrowed = false;
}

LibraryBook::~LibraryBook()
{
    cout << "Book Object Destroyed: " << title << endl;
}

// Setters
void LibraryBook::setBookID(int id)
{
    bookID = id;
}

void LibraryBook::setTitle(string t)
{
    title = t;
}

void LibraryBook::setAuthor(string a)
{
    author = a;
}

void LibraryBook::setBorrowerName(string name)
{
    borrowerName = name;
}

void LibraryBook::setDaysBorrowed(int days)
{
    daysBorrowed = days;
}

void LibraryBook::setBorrowed(bool status)
{
    borrowed = status;
}

// Getters
int LibraryBook::getBookID() const
{
    return bookID;
}

string LibraryBook::getTitle() const
{
    return title;
}

string LibraryBook::getAuthor() const
{
    return author;
}

string LibraryBook::getBorrowerName() const
{
    return borrowerName;
}

int LibraryBook::getDaysBorrowed() const
{
    return daysBorrowed;
}

bool LibraryBook::getBorrowed() const
{
    return borrowed;
}

// Methods
void LibraryBook::borrowBook(string borrower, int days)
{
    borrowed = true;
    borrowerName = borrower;
    daysBorrowed = days;
}

void LibraryBook::returnBook()
{
    borrowed = false;
    borrowerName = "";
    daysBorrowed = 0;
}

bool LibraryBook::isOverdue() const
{
    return daysBorrowed > 14;
}

double LibraryBook::calculateFine() const
{
    if (daysBorrowed > 14)
        return (daysBorrowed - 14) * 1.0;

    return 0;
}

void LibraryBook::displayBook() const
{
    cout << "\nBook ID: " << bookID
         << "\nTitle: " << title
         << "\nAuthor: " << author
         << "\nBorrow Status: ";

    if (borrowed)
    {
        cout << "Borrowed";
        cout << "\nBorrower: " << borrowerName;
        cout << "\nDays Borrowed: " << daysBorrowed;
    }
    else
    {
        cout << "Available";
    }

    cout << endl;
}
