#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initial_balance);
    void deposit(double amount);
    bool withdraw(double amount);
    double getBalance() const;
};

#endif
