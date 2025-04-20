#include "BankAccount.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount(double initial_balance) : balance(initial_balance) {}

void BankAccount::deposit(double amount) {
    if(amount > 0)
        balance += amount;
}

bool BankAccount::withdraw(double amount) {
    if(amount <= balance) {
        balance -= amount;
        return true;
    }
    else {
        cout << "Insufficient funds" << endl;
        return false;
    }
}

double BankAccount::getBalance() const {
    return balance;
}
