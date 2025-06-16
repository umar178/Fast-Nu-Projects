#include<iostream>
using namespace std;

class BankAccount{
	double balance;
	double withdraw;
	public:
		BankAccount(double bal,double with=0):balance(bal),withdraw(with){}
		
		void withdrawAmount(){
			cout<<"Current Balance: "<<balance<<endl;
			cout<<"Enter withdrawl amount: ";
			cin>>withdraw;
			if(withdraw>balance){
				throw "Error: Insufficient funds to complete withdrawal!";
			}
			cout<<"Withdrawal successful! New Balance: $"<<(balance-withdraw)<<endl;
		}
};

int main(){
	BankAccount b1(500.0);
	try{
		b1.withdrawAmount();
	}
	catch(const char *c){
		cout<<c<<endl;
	}
	
	try{
		b1.withdrawAmount();
	}
	catch(const char *c){
		cout<<c<<endl;
	}
}
