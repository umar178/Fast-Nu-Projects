#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title, author, ISBN;
    bool isAvailable;

    void addBook() {
        cin.ignore();
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        getline(cin, ISBN);
        isAvailable = true;
        cout << "Book added successfully!\n";
    }

    void displayBook() {
        cout << "\nTitle: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN 
             << "\nAvailability: " << (isAvailable ? "Available" : "Issued") << "\n";
    }

    void updateAvailability() {
        isAvailable = !isAvailable;
        cout << "Book availability updated successfully!\n";
    }

    bool searchBook(string query) {
        return title == query || ISBN == query;
    }
};

int main() {
    vector<Book> library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Display All Books\n3. Search Book\n4. Update Availability\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Book book;
            book.addBook();
            library.push_back(book);
        } 
        else if (choice == 2) {
            if (library.empty()) cout << "No books available.\n";
            else {
                for (int i = 0; i < library.size(); i++) {
                    library[i].displayBook();
                }
            }
        } 
        else if (choice == 3) {
            cin.ignore();
            string query;
            cout << "Enter book title or ISBN to search: ";
            getline(cin, query);
            bool found = false;
            for (int i = 0; i < library.size(); i++) {
                if (library[i].searchBook(query)) {
                    library[i].displayBook();
                    found = true;
                }
            }
            if (!found) cout << "Book not found.\n";
        } 
        else if (choice == 4) {
            cin.ignore();
            string query;
            cout << "Enter book title or ISBN to update availability: ";
            getline(cin, query);
            bool found = false;
            for (int i = 0; i < library.size(); i++) {
                if (library[i].searchBook(query)) {
                    library[i].updateAvailability();
                    found = true;
                }
            }
            if (!found) cout << "Book not found.\n";
        } 
        else if (choice == 5) {
            cout << "Exiting Library System...\n";
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

