#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file;
    file.open("data.txt", ios::app);
    if (!file) {
        cout << "Failed to open file!" << endl;
        return 1;
    }

    file << "This line is appended using the open() method. \n";
    file.close();

    cout << "Data written successfully." << endl;
    return 0;
}
