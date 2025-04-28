#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream read("secret.txt");
	if(read.is_open()){
		char ch;
		int count=0;
		while(read.get(ch)){
			if(ch>=65 && ch<=90){
				cout<<ch<<" ";
				count++;
			}
		}
		read.close();
		cout<<"The total number of upper case characters are "<<count<<endl;
	}
}
