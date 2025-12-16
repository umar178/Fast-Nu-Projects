#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    Book* next;
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        next = NULL;
    }
};

class BookList {
public:
    Book* head;
    BookList() { head = NULL; }

    void insertAtBeginning(int id, string title, string author) {
        Book* n = new Book(id, title, author);
        n->next = head;
        head = n;
    }

    void insertAtEnd(int id, string title, string author) {
        Book* n = new Book(id, title, author);
        if (!head) { head = n; return; }
        Book* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void insertAtPosition(int pos, int id, string title, string author) {
        if (pos == 1) { insertAtBeginning(id, title, author); return; }
        Book* n = new Book(id, title, author);
        Book* temp = head;
        for (int i = 1; i < pos - 1 && temp; i++) temp = temp->next;
        if (!temp) return;
        n->next = temp->next;
        temp->next = n;
    }

    void deleteFromBeginning() {
        if (!head) return;
        Book* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Book* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteFromPosition(int pos) {
        if (!head) return;
        if (pos == 1) { deleteFromBeginning(); return; }
        Book* temp = head;
        for (int i = 1; i < pos - 1 && temp->next; i++) temp = temp->next;
        if (!temp->next) return;
        Book* del = temp->next;
        temp->next = del->next;
        delete del;
    }

    void searchById(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "ID: " << temp->id << "\nTitle: " << temp->title << "\nAuthor: " << temp->author << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found" << endl;
    }

    void display() {
        Book* temp = head;
        while (temp) {
            cout << temp->id << " " << temp->title << " " << temp->author << endl;
            temp = temp->next;
        }
    }
};

int main() {
    BookList mine;
    mine.insertAtBeginning(101, "C++", "Bjarne");
    mine.insertAtEnd(102, "Python", "Guido");
    mine.insertAtPosition(2, 103, "Java", "James");
    mine.display();
    mine.searchById(102);
    mine.deleteFromBeginning();
    mine.deleteFromEnd();
    mine.deleteFromPosition(1);
    mine.display();
}

