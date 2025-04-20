#include <iostream>
#include "BankAccount.h"
#include "BankAccount.cpp"
using namespace std;

int main() {
    BankAccount account(1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);
    cout << "Current balance: $" << account.getBalance() << endl;
    return 0;
}
