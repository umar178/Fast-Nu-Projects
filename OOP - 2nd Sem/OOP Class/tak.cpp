#include <iostream>
using namespace std;
class student{
	public:
		string name;
		student(){
			name = "unknown";
		}
		student(string name){
			this->name = name;
		}
		~student(){
			cout<<"The name is "<<name<<endl;
		}
};
int main(){
	student s1("Rayyan");
	student s2;
}
