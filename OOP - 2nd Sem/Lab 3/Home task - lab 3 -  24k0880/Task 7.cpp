#include <iostream>
using namespace std;

class ATM {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    ATM(string name, int accNum, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    void checkBalance() {
        cout << "\nCurrent Balance: $" << balance << "\n";
    }

    void depositMoney() {
        double amount;
        cout << "Enter deposit amount: $";
        cin >> amount;
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! New Balance: $" << balance << "\n";
        } else {
            cout << "Invalid amount. Deposit failed.\n";
        }
    }

    void withdrawMoney() {
        double amount;
        cout << "Enter withdrawal amount: $";
        cin >> amount;
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Remaining Balance: $" << balance << "\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void displayMenu() {
        int choice;
        do {
            cout << "\nATM Menu\n";
            cout << "1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    depositMoney();
                    break;
                case 3:
                    withdrawMoney();
                    break;
                case 4:
                    cout << "Exiting ATM. Thank you!\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    string name;
    int accNum;
    double initialBalance;

    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accNum;
    cout << "Enter initial balance: $";
    cin >> initialBalance;

    ATM userATM(name, accNum, initialBalance);
    userATM.displayMenu();

    return 0;
}

