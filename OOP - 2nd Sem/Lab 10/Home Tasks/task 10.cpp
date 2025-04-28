#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream write("backup_log.txt",ios::app);
	string temp;
	cout<<"Enter text that is needed to be added in file:"<<endl;
	getline(cin,temp);
	write<<temp;
	streampos size=write.tellp();
	cout<<"The final size of file is "<<size<<" bytes"<<endl;
}
