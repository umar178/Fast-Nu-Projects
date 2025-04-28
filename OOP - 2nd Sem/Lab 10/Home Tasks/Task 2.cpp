#include<iostream>
#include<fstream>
using namespace std;

int main(){
	ifstream read("greeting.txt");
	
	if(!read.is_open()){
		cout<<"Error! No file available";
		return 1;
	}
	ofstream write("diary.txt",ios::app);
	int choice;
	do{
		cout<<"1: Write in diary.txt"<<endl;
		cout<<"2: Exit"<<endl;
		cin>>choice;
		switch(choice){
			case 1:
				string text;
				getline(read,text);
				write<<text;
				cout<<"The text '"<<text<<"' is written in diary.txt\n";
				break;
		}
	}while(choice!=2);
}


