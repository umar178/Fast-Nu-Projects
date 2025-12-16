#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    while (!isPrime(n)) {
        n++;
    }
    return n;
}

struct HashTable {
    int* table;
    int capacity;
    int count;

    HashTable(int size) {
        capacity = size;
        count = 0;
        table = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = -1; 
        }
    }

    double getLoadFactor() {
        return (double)count / capacity;
    }

    void rehash() {
        int oldCapacity = capacity;
        int* oldTable = table;

        int newCapacity = nextPrime(oldCapacity * 2);
        
        cout << "\n[Rehashing Triggered!]" << endl;
        cout << "Old Size: " << oldCapacity << " -> New Size: " << newCapacity << endl;

        table = new int[newCapacity];
        capacity = newCapacity;
        count = 0; 
        
        for (int i = 0; i < capacity; i++) {
            table[i] = -1;
        }

        cout << "Migrating elements..." << endl;
        for (int i = 0; i < oldCapacity; i++) {
            if (oldTable[i] != -1) {
                insertWithoutResize(oldTable[i]); 
            }
        }

        delete[] oldTable;
        cout << "Rehashing Complete.\n" << endl;
    }

    void insertWithoutResize(int key) {
        int index = key % capacity;
        
        while (table[index] != -1) {
            index = (index + 1) % capacity;
        }
        
        table[index] = key;
        count++;
    }

    void insert(int key) {
        if (getLoadFactor() >= 0.75) {
            rehash();
        }

        int index = key % capacity;
        
        while (table[index] != -1) {
            index = (index + 1) % capacity;
        }

        table[index] = key;
        count++;
        
        cout << "Inserted key " << key << ". Current Load Factor: " << getLoadFactor() << endl;
    }

    void display() {
        cout << "Table State (Size " << capacity << "): ";
        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1) cout << "[" << table[i] << "] ";
            else cout << "[_] ";
        }
        cout << endl;
    }
};

int main() {
    cout << "--- Initializing Table with size 4 ---" << endl;
    HashTable ht(4);

    ht.insert(10);
    ht.insert(20); 
    ht.insert(30); 
    
    ht.display();

    ht.insert(40); 

    ht.display();
    
    return 0;
}
