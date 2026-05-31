#include "Functions.h"

int main()
{
    const int SIZE = 100;

    LibraryBook books[SIZE];
    int count = 0;

    int choice;

    do
    {
        cout << "\n===== LIBRARY BOOK BORROWING SYSTEM =====\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search Book by ID\n";
        cout << "6. Display Overdue Books\n";
        cout << "7. Calculate Total Fines\n";
        cout << "8. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook(books, count);
            break;

        case 2:
            displayBooks(books, count);
            break;

        case 3:
            borrowBookMenu(books, count);
            break;

        case 4:
            returnBookMenu(books, count);
            break;

        case 5:
            searchBook(books, count);
            break;

        case 6:
            displayOverdueBooks(books, count);
            break;

        case 7:
            calculateTotalFines(books, count);
            break;

        case 8:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 8);

    return 0;
}
