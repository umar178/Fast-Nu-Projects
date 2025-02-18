#include <iostream>

using namespace std;

class bank {
public:
    string accountHolder;
    double balance;

    static double totalBalance; 

    bank(string name, double i_balance) : accountHolder(name), balance(i_balance) {
        totalBalance += i_balance;
    }

    void deposit(double amount) {
        balance += amount; 
        totalBalance += amount;
        cout << "Deposited " << amount << " into " << accountHolder << "'s account." << endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance in " << accountHolder << "'s account." << endl;
        } else {
            balance -= amount;
            totalBalance -= amount;
            cout << "Withdrawn " << amount << " from " << accountHolder << "'s account." << endl;
        }
    }

    static double getTotalBalance() {
        return totalBalance;
    }

    void displayAccount() {
        cout << "Account Holder: " << accountHolder << ", Balance: " << balance << endl;
    }
};

double bank::totalBalance = 0.0;

int main() {
    bank a1("Ahmed", 1000);
    bank a2("Shafique", 2000);

    cout << "Initial Total Balance: " << bank::getTotalBalance() << endl; 

    cout << "Account Details:" << endl;
    a1.displayAccount();
    a2.displayAccount();

    a1.deposit(500);
    a2.withdraw(1000);

    cout << "Changed Total Balance: " << bank::getTotalBalance() << endl; 
    return 0;
}

