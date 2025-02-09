#include<iostream>

using namespace std;

class student{
	private:
		int rollno;
	
	public:
		
		void setroll(int i){
			rollno = i;
		}
		
		int getroll(){
			return rollno;
		}
};

main(){
	student a;
	
	a.setroll(240880);
	cout<<a.getroll();
}
