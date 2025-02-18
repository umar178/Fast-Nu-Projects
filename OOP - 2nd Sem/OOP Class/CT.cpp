#include<iostream>

using namespace std;

class student{
	string name;
	
	public:
		student(string word="unknown"){
			name = word;
		}
		
		~student(){
			cout<<"Student "<<name<<" deleted."<<endl;
		}
		
		void displayName(){
			cout<<"Student name is: "<< name <<endl;
		}
};

main(){
	student s1;
	student s2("Umar");
	s1.displayName();
	s2.displayName();
}
