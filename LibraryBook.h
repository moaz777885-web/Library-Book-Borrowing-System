#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <iostream>
#include <string>
using namespace std;

class LibraryBook
{
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool borrowed;

public:
    // Default Constructor
    LibraryBook();

    // Parameterized Constructor
    LibraryBook(int id, string t, string a);

    // Destructor
    ~LibraryBook();

    // Setters
    void setBookID(int id);
    void setTitle(string t);
    void setAuthor(string a);
    void setBorrowerName(string name);
    void setDaysBorrowed(int days);
    void setBorrowed(bool status);

    // Getters
    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getBorrowed() const;

    // Methods
    void borrowBook(string borrower, int days);
    void returnBook();
    double calculateFine() const;
    bool isOverdue() const;
    void displayBook() const;
};

#endif
