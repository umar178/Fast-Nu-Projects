#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool available;

public:
    Book(string t, string a) : title(t), author(a), available(true) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool isAvailable() const { return available; }

    void borrowBook() { available = false; }
    void returnBook() { available = true; }
};

class User {
public:
    void searchBook(const vector<Book>& books, const string& title) {
        for (const Book& book : books) {
            if (book.getTitle() == title) {
                cout << "Found: " << book.getTitle() << " by " << book.getAuthor();
                cout << " (" << (book.isAvailable() ? "Available" : "Borrowed") << ")" << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void borrowBook(vector<Book>& books, const string& title) {
        for (Book& book : books) {
            if (book.getTitle() == title && book.isAvailable()) {
                book.borrowBook();
                cout << "You've borrowed: " << book.getTitle() << endl;
                return;
            }
        }
        cout << "Book not available for borrowing." << endl;
    }
};

class Librarian : public User {
public:
    void addBook(vector<Book>& books, const string& title, const string& author) {
        books.emplace_back(title, author);
        cout << "Added book: " << title << " by " << author << endl;
    }

    void removeBook(vector<Book>& books, const string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getTitle() == title) {
                cout << "Removed book: " << it->getTitle() << endl;
                books.erase(it);
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    vector<Book> books;
    Librarian librarian;
    User user;

    librarian.addBook(books, "The Great Gatsby", "F. Scott Fitzgerald");
    librarian.addBook(books, "1984", "George Orwell");

    user.searchBook(books, "1984");
    user.borrowBook(books, "1984");
    user.searchBook(books, "1984");
    
    return 0;
}
