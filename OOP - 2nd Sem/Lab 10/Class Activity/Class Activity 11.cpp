#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFile("read fileexample.txt");
    char ch;

    if (inFile.is_open()) {
        while (inFile.get(ch)) {
            cout << ch;
        }
        inFile.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}
