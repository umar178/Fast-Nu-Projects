#include<iostream>

using namespace std;

class castle{
	int people;
	
	public:
		castle(){
			people = 0;
		}
		
		void display(){
			cout<<"Members: "<< people<<endl;
		}
		
		void enter(){
			if(people >= 10){
				throw people;
			}
			
			people++;
		}
		
		void exit(){
			if(people <= 0){
				throw people;
			}
			people--;
		}
};

int main(){
	castle C;
	int op;
	op = 1;
	
	while(op != 0){
		cout<<endl;
		cout<<"Current Details:" << endl;
		C.display();
		cout<<endl;
		cout<<"Enter operation:\n 0:Exit Program \n 1: Enter \n 2: Exit\n";
		cin>>op;
		
		if(op == 1){
			try{
				C.enter();	
			}
			catch(int i){
				cout<<"“Count Overflow”"<<endl;
			}
		}
		else if(op == 2){
			try{
				C.exit();	
			}
			catch(int i){
				cout<<"Count Underflow"<< endl;
			}
		}
		
	}
	
	
}
