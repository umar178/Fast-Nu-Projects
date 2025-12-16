#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) { data = d; next = NULL; }
};

Node* mergeSorted(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* head = NULL;
    if (a->data < b->data) { head = a; a = a->next; }
    else { head = b; b = b->next; }
    Node* tail = head;
    while (a && b) {
        if (a->data < b->data) { tail->next = a; a = a->next; }
        else { tail->next = b; b = b->next; }
        tail = tail->next;
    }
    tail->next = (a) ? a : b;
    return head;
}

void display(Node* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* A = new Node(1);
    A->next = new Node(3);
    A->next->next = new Node(5);
    Node* B = new Node(2);
    B->next = new Node(4);
    B->next->next = new Node(6);
    Node* merged = mergeSorted(A, B);
    display(merged);
}

