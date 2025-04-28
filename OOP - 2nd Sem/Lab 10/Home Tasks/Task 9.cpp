#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	fstream file("draft.txt", ios::out | ios::in);
	streampos position;
	string word;
	string toFind="teh";
	while(file>>word){
		position=file.tellg();
		if(word==toFind){
			cout<<"Word is found and updated"<<endl;
			position-=word.length();
			file.seekp(position);
			file<<"the";
		}
	}
}
