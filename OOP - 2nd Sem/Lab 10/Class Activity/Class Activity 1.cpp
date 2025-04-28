#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outputFile("example.txt");

    if (!outputFile) {
        cout << "Error: File could not be created!" << endl;
        return 1;
    }

    outputFile << "Hello, this file was opened using the constructor method.\n";
    outputFile << "File handling in C++ is fun and useful\n";

    outputFile.close();

    cout << "Data successfully written to example.txt" << endl;

    return 0;
}
