#include<iostream>
#include<fstream>
using namespace std;

 struct Student{
 	char name[50];
 	int id;
 	float gpa;
 };
 
 int main(){
 	Student s1[3];
 	
 	for(int i=0;i<3;i++){
 		cout<<"For Student:"<<i+1<<endl;
 		
 		cout<<"Enter name: ";
 		cin>>s1[i].name;
 		
 		cout<<"Enter id: ";
 		cin>>s1[i].id;
 		
 		cout<<"Enter GPA: ";
 		cin>>s1[i].gpa;
	 }
	 
	ofstream outFile("BinaryFile.dat",ios::binary);
	for(int i=0;i<3;i++){
		outFile.write((char*)&s1[i],sizeof(s1[i]));
	}
	outFile.close();
	
	Student s2[3];
	
	ifstream inFile("BinaryFile.dat",ios::binary);
	
	for(int i=0;i<3;i++){
		inFile.read((char*)&s2[i],sizeof(s2[i]));
	}
	inFile.close();
	
	for(int i=0;i<3;i++){
		cout<<"Name: "<<s2[i].name<<" | Id: "<<s2[i].id<<" | GPA: "<<s2[i].gpa<<endl;
	}
 }
