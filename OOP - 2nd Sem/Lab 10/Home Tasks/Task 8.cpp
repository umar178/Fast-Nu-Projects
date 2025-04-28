#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream read("article.txt", ios::in);
	
	read.seekg(0,ios::end);
	streampos deadEnd=read.tellg();
	streampos middle=deadEnd/2;
	
	read.seekg(middle,ios::beg);
	string buffer;
	while(getline(read,buffer)){
		cout<<buffer<<endl;
	}
}
