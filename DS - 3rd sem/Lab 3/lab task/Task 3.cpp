#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void insertEnd(int d) {
        Node* n = new Node(d);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void rearrangeEvenOdd() {
        if (!head || !head->next) return;
        Node* evenStart = NULL;
        Node* evenEnd = NULL;
        Node* oddStart = NULL;
        Node* oddEnd = NULL;
        Node* curr = head;
        while (curr) {
            if (curr->data % 2 == 0) {
                if (!evenStart) { evenStart = evenEnd = curr; }
                else { evenEnd->next = curr; evenEnd = curr; }
            } else {
                if (!oddStart) { oddStart = oddEnd = curr; }
                else { oddEnd->next = curr; oddEnd = curr; }
            }
            curr = curr->next;
        }
        if (!evenStart || !oddStart) return;
        evenEnd->next = oddStart;
        oddEnd->next = NULL;
        head = evenStart;
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    LinkedList mine;
    int arr[] = {17,15,8,12,10,5,4,1,7,6};
    for (int x : arr) mine.insertEnd(x);
    mine.rearrangeEvenOdd();
    mine.display();
}

