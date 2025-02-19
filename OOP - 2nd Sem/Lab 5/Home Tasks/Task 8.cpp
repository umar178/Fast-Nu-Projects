#include <iostream>
using namespace std;

class LoanAccount {
private:
    const int accountNumber;
    double loanBalance;

public:
    LoanAccount(int accNo, double balance) : accountNumber(accNo), loanBalance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getLoanBalance() const {
        return loanBalance;
    }

    void applyPayment(double amount) {
        loanBalance -= amount;
    }

    void takeLoan(double amount) {
        loanBalance += amount;
    }

    void display() {
        cout << "Account No: " << accountNumber << " | Loan Balance: $" << loanBalance << endl;
    }
};

int main() {
    LoanAccount acc1(1001, 5000);
    acc1.display();
    acc1.applyPayment(1000);
    acc1.display();
    acc1.takeLoan(2000);
    acc1.display();
    return 0;
}

