#include <iostream>
using namespace std;
#include <string>
class student{
	string name;
	int rollno;
	int age;
	public:
		student(string n,int r,int a): name(n),rollno(r),age(a){}
		void displaystudent(){
			cout<<name<<endl<<rollno<<endl<<age<<endl;
		}
		
};
int main(){
	student A("Umar",240880,18);
	A.displaystudent();
	return 0;
}
