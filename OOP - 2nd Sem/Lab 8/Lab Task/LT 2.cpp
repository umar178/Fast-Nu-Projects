#include <iostream>
using namespace std;

class Librarian;

class Book {
private:
    string title;
    double price;

public:
    Book(string t, double p) : title(t), price(p) {}

    friend class Librarian;
};

class Librarian {
public:
    void displayBookDetails(const Book& book) {
        cout << "Book Title: " << book.title << endl;
        cout << "Book Price: $" << book.price << endl;
    }

    void applyDiscount(Book& book, double discount) {
        book.price -= discount;
        cout << "Discounted Price: $" << book.price << endl;
    }
};

int main() {
    Book book("C++ Programming", 45.99);
    Librarian librarian;

    librarian.displayBookDetails(book);
    librarian.applyDiscount(book, 10.0);

    return 0;
}
