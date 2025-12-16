#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int d) { data = d; next = prev = NULL; }
};

class Deque {
public:
    DNode* front;
    DNode* rear;
    Deque() { front = rear = NULL; }

    void insertFront(int x) {
        DNode* n = new DNode(x);
        if (!front) { front = rear = n; return; }
        n->next = front;
        front->prev = n;
        front = n;
    }

    void insertRear(int x) {
        DNode* n = new DNode(x);
        if (!rear) { front = rear = n; return; }
        rear->next = n;
        n->prev = rear;
        rear = n;
    }

    void deleteFront() {
        if (!front) return;
        DNode* temp = front;
        front = front->next;
        if (front) front->prev = NULL;
        else rear = NULL;
        delete temp;
    }

    void deleteRear() {
        if (!rear) return;
        DNode* temp = rear;
        rear = rear->prev;
        if (rear) rear->next = NULL;
        else front = NULL;
        delete temp;
    }

    int getFront() { return front ? front->data : -1; }
    int getRear() { return rear ? rear->data : -1; }

    void display() {
        DNode* temp = front;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    Deque mine;
    mine.insertFront(10);
    mine.insertRear(20);
    mine.insertFront(5);
    mine.display();
    cout << mine.getFront() << " " << mine.getRear() << endl;
    mine.deleteFront();
    mine.deleteRear();
    mine.display();
}

