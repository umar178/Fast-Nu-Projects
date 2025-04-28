#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream file("debug.txt");
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file 'debug.txt'" << endl;
        return 1;
    }
    
    cout << "Enter the position of cursor in FILE: ";
    int temp;
    cin >> temp;
    
    file.seekg(temp, ios::beg);
    if (file.fail()) {
        cerr << "Error: Invalid position in file" << endl;
        return 1;
    }
    
    streampos position = file.tellg();
    cout << "Pointer position before: " << position << endl << endl;
    
    int count = 0;
    char ch;
    while (count < 99 && file.get(ch)) {
        count++;
        cout << ch;
    }
    
    if (file.eof()) {
        cout << "\n\nReached end of file after " << count << " characters" << endl;
    }
    
    position = file.tellg();
    cout << "\nPointer position after: " << position << endl;
    
    return 0;
}
