#include <iostream>
using namespace std;

class BankAccount;

class Transaction {
public:
    friend void processTransaction(BankAccount& acc, float amount, string type);
};

class BankAccount {
private:
    int accountNumber;
    float balance;

public:
    BankAccount(int accNo, float bal) : accountNumber(accNo), balance(bal) {}
    friend void processTransaction(BankAccount& acc, float amount, string type);

    void display() const {
        cout << "Account " << accountNumber << " Balance: " << balance << endl;
    }
};

void processTransaction(BankAccount& acc, float amount, string type) {
    if (type == "deposit") acc.balance += amount;
    else if (type == "withdraw" && acc.balance >= amount) acc.balance -= amount;
    else cout << "Invalid or insufficient funds.\n";
}

int main() {
    BankAccount acc(12345, 1000.0);
    acc.display();

    processTransaction(acc, 200, "deposit");
    processTransaction(acc, 100, "withdraw");
    acc.display();

    return 0;
}

