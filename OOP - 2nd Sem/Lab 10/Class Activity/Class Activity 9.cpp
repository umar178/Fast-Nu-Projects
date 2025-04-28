#include <iostream> 
#include <fstream> 
using namespace std; 

int main() { 
    ifstream inFile("read fileexample.txt"); string word; 
    if (inFile.is_open()) { 
        while (inFile >> word) { 
        } 
    cout << word << endl; 
    inFile.close(); 
    } else { 
    cout << "File not found." << endl; 
    } 
    return 0; 
}