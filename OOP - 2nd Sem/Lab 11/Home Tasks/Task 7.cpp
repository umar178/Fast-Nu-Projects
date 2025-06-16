#include<iostream>
using namespace std;
template <typename T>
class SmartArray{
	private:
	int size;
	T *array;
	public:
		SmartArray(){
			cout<<"Array size: ";
			cin>>size;
			array=new T[size];
			cout<<"Enter elements: "<<endl;
			for(int i=0;i<size;i++){
				cin>>array[i];
			}
		}
		
		void operator[](int index){
			cout<<"Accessing index "<<index<<":";
			if(index>=size || index<0){
				cout<<endl;
				throw "OutOfBoundsException caught: Invalid index access attempted!";
			}
			for(int i=0;i<size;i++){
				if(i==(index-1)){
					cout<<array[i]<<endl;
					return;
				}
			}
		}
		~SmartArray(){
			delete[] array;
			
		}
};

int main(){
	SmartArray<int> s1;
	try{
		s1[3];
		s1[5];
	}
	catch(const char *c){
		cout<<c<<endl;
	}
}
