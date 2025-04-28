#include <iostream>
using namespace std;

class BankAccount1 {
private:
    double balance;

public:
    double getBalance() const {
        return balance;
    }

    void setBalance(double newBalance) {
        balance = newBalance;
    }
};

class BankAccount2 {
private:
    double balance;

public:
    BankAccount2() : balance(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << ". Remaining balance: " << balance << endl;
            return true;
        }
        cout << "Withdrawal failed. Insufficient funds or invalid amount." << endl;
        return false;
    }
};

int main() {
    BankAccount1 acc1;
    acc1.setBalance(1000); 
    cout << "Account 1 balance: " << acc1.getBalance() << endl;

    BankAccount2 acc2;
    acc2.deposit(500);     
    acc2.withdraw(200);
    acc2.withdraw(400);    
    return 0;
}
