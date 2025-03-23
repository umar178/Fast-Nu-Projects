#include<iostream>
using namespace std;
class BankAccount{
	public:
	virtual void withdraw(){
		cout<<"Amount withdrawn";
	}
};

class SavingsAccount:public BankAccount{
	public:
	void withdraw(){
		cout<<"Savings Account Withdrawal: $500"<<endl;
	}
};

class CurrentAccount:public BankAccount{
	public:
	void withdraw(){
		cout<<"Current Account Withdrawal: $1000"<<endl;
	}
};

int main(){
	BankAccount *b1;
	BankAccount *b2;
	
	SavingsAccount s1;
	CurrentAccount c1;
	b1=&s1;
	b2=&c1;
	b1->withdraw();
	b2->withdraw();
}
