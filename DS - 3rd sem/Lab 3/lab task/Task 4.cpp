#include <iostream>
using namespace std;

class CharNode {
public:
    char data;
    CharNode* next;
    CharNode(char d) { data = d; next = NULL; }
};

class LinkedList {
public:
    CharNode* head;
    LinkedList() { head = NULL; }

    void insertEnd(char d) {
        CharNode* n = new CharNode(d);
        if (!head) { head = n; return; }
        CharNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    bool isPalindrome() {
        CharNode* slow = head;
        CharNode* fast = head;
        CharNode* prev = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            CharNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }
        CharNode* left = prev;
        CharNode* right = (fast) ? slow->next : slow;
        while (left && right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

int main() {
    LinkedList mine;
    string s = "level";
    for (char c : s) mine.insertEnd(c);
    cout << (mine.isPalindrome() ? "true" : "false") << endl;
}

