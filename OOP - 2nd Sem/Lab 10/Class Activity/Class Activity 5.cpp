#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file;
    file.open("output.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    file << "This is a basic example of writing to a file in C++.\n";
    file << "File handling makes data storage easier. \n";

    file.close();

    cout << "Data written to file successfully." << endl;
    return 0;
}
