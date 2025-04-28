#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream read("story.txt");
	if(read.is_open()){
		string word;
		while(read>>word){
			cout<<word<<endl;
		}
		read.close();
	}
	else{
		cout<<"Error";
	}
}
