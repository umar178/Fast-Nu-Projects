#include<iostream>

using namespace std;

class account{
	public:
		int accno;
		string name;
		
		static float rateofinterest;
		
		account(int accno, string name){
			this->name = name;
			this->accno = accno;
		}
		
		void display(){
			cout<<accno<<" "<<name<<" "<<rateofinterest<<endl;
		}
};

float account::rateofinterest = 6.5;

main(){
	account a1 = account(900, "Ahmed");
	account a2 = account(780, "Shafique");
	
	a1.display();
	a2.display();
}
