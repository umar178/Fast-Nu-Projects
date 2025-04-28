#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream read("report.txt",ios::app | ios::out |ios::in);
	
	int Character=0,punc=0;
	char ch;
	while(read.get(ch)){
		if(ch>=33 && ch<=63){
			punc++;
			continue;
		}
		Character++;
	}
	
	read.clear();
	read.seekg(0,ios::beg);
	
	int Word=0;
	string word;
	while(read>>word){
		Word++;
	}
	
	read.clear();
	read.seekg(0,ios::beg);
	
	int line=0;
	while(getline(read,word)){
		line++;
		
	}
	
	read.clear();
    read.seekp(0, ios::end);
    
	read<<"characters: "<<Character<<endl;
	read<<"Word: "<<Word<<endl;
	read<<"Line: "<<line<<endl;
	read<<"Punctuation Mark: "<<punc<<endl;
}
