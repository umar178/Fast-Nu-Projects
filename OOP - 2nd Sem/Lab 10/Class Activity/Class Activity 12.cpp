#include <iostream>
#include <fstream>
using namespace std;

class CharFileReader {
private:
    ifstream file;

public:
    CharFileReader(const string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            cerr << "Unable to open file." << endl;
            exit(1);
        }
    }

    void displayChars() {
        char ch;
        while (file.get(ch)) {
            cout << ch;
        }
    }

    ~CharFileReader() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    CharFileReader reader("readfileexample.txt");
    reader.displayChars();
    return 0;
}
