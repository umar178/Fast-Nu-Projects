#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string title, author;

public:
    LibraryItem(string t, string a) : title(t), author(a) {}

    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem {
private:
    string ISBN;

public:
    Book(string t, string a, string i) : LibraryItem(t, a), ISBN(i) {}

    void displayDetails() const override {
        cout << "=== Book Details ===\nTitle: " << title << "\nAuthor: " << author << "\nISBN: " << ISBN << endl;
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(string t, string a, int i) : LibraryItem(t, a), issueNumber(i) {}

    void displayDetails() const override {
        cout << "=== Magazine Details ===\nTitle: " << title << "\nAuthor: " << author << "\nIssue Number: " << issueNumber << endl;
    }
};

int main() {
    Book b("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565");
    Magazine m("National Geographic", "Multiple Authors", 202);

    b.displayDetails();
    cout << endl;
    m.displayDetails();

    return 0;
}

