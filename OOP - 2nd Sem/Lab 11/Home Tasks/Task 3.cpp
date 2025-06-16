#include<iostream>
using namespace std;
template<typename T,typename U>
class Pair{
	T value1;
	U value2;
	public:
		Pair(T v1,U v2){
			value1=v1;
			value2=v2;
		}
		void display(){
			cout<<"Pair:("<<value1<<","<<value2<<")"<<endl;
		}
};

int main(){
	Pair<int,string> p1(5,"Hello");
	p1.display();
	
	Pair<double,int> p2(3.14,42);
	p2.display();
}
