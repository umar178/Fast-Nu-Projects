#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

int main(){
	ofstream write("system_log.txt",ios::app);
	
	time_t now = time(NULL);
	tm* local_time = localtime(&now);
	char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
    
	write<<"System started at: "<<buffer<<"\n";
}
