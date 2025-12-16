#include <iostream>

using namespace std;

const int TABLE_SIZE = 7;

void solveLinearProbing(int keys[], int numKeys) {
    cout << "--- Part 1: Linear Probing ---\n";
    int table[TABLE_SIZE];
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = -1;
    }

    bool firstCollisionFound = false;

    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int hashIndex = key % TABLE_SIZE;
        int currentIndex = hashIndex;
        
        cout << "Inserting Key " << key << ": Hash(" << key << ") = " << hashIndex;

        if (table[currentIndex] != -1) {
            cout << " -> Collision at index " << currentIndex;
            
            if (!firstCollisionFound) {
                cout << " [FIRST COLLISION DETECTED]";
                firstCollisionFound = true;
            }

            int probes = 0;
            while (table[currentIndex] != -1 && probes < TABLE_SIZE) {
                currentIndex = (currentIndex + 1) % TABLE_SIZE;
                probes++;
            }
            cout << " -> Probed to index " << currentIndex;
        }

        table[currentIndex] = key;
        cout << " -> Placed at index " << currentIndex << endl;
    }

    cout << "\nFinal Linear Probing Table:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        if (table[i] == -1) cout << "Empty";
        else cout << table[i];
        cout << endl;
    }
    cout << endl;
}

struct Node {
    int data;
    Node* next;
};

void solveSeparateChaining(int keys[], int numKeys) {
    cout << "--- Part 2: Separate Chaining ---\n";
    
    Node* table[TABLE_SIZE];
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }

    for (int i = 0; i < numKeys; i++) {
        int key = keys[i];
        int index = key % TABLE_SIZE;

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = nullptr;

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    cout << "Final Separate Chaining Table Structure:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";
        Node* temp = table[i];
        if (temp == nullptr) {
            cout << "NULL";
        } else {
            while (temp != nullptr) {
                cout << temp->data;
                if (temp->next != nullptr) cout << " -> ";
                temp = temp->next;
            }
        }
        cout << endl;
    }

    cout << "\nAnalysis for Key 55:\n";
    int idx55 = 55 % TABLE_SIZE;
    cout << "Calculated Hash Index: " << idx55 << endl;
    cout << "Final Placement: Index " << idx55 << ", linked after key 76." << endl;
}

int main() {
    int keys[] = {76, 93, 40, 47, 10, 55};
    int numKeys = 6;

    solveLinearProbing(keys, numKeys);
    
    cout << "------------------------------------------------\n";

    solveSeparateChaining(keys, numKeys);

    return 0;
}
