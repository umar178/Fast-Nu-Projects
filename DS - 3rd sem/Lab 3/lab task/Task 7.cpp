#include <iostream>
using namespace std;

class SNode {
public:
    int data;
    SNode* next;
    SNode(int d) { data = d; next = NULL; }
};

class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int d) { data = d; next = prev = NULL; }
};

SNode* createSampleSLL() {
    SNode* head = new SNode(1);
    head->next = new SNode(2);
    head->next->next = new SNode(3);
    return head;
}

DNode* convertToDLL(SNode* head) {
    if (!head) return NULL;
    DNode* dHead = new DNode(head->data);
    DNode* temp = dHead;
    head = head->next;
    while (head) {
        DNode* n = new DNode(head->data);
        temp->next = n;
        n->prev = temp;
        temp = n;
        head = head->next;
    }
    return dHead;
}

SNode* convertToCircular(SNode* head) {
    if (!head) return NULL;
    SNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = head;
    return head;
}

void displaySLL(SNode* head, int n) {
    SNode* temp = head;
    for (int i = 0; i < n; i++) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

void displayDLL(DNode* head) {
    DNode* temp = head;
    while (temp) { cout << temp->data << " "; temp = temp->next; }
    cout << endl;
}

int main() {
    SNode* sll = createSampleSLL();
    DNode* dll = convertToDLL(sll);
    displayDLL(dll);
    SNode* circular = convertToCircular(sll);
    displaySLL(circular, 6);
}

