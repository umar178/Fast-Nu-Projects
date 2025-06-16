#include<iostream>
#include<string>
using namespace std;

template <typename T>
void findMax(T *array,int size){
	T max=array[0];
	for(int i=1;i<size;i++){
		if(array[i]>max){
			max=array[i];
		}
	}
	cout<<"Maximum: "<<max<<endl;
}

int main(){
	int arr[5]={10,20,5,30,25};
	findMax(arr,5);
	string array[5]={"Apple","Mango","Banana","Peach"};
	findMax(array,5);
}
