#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileReader {
private:
    ifstream file;
    string filename;
public:
    FileReader(const string& fname) : filename(fname) {
        file.open(filename);
    }

    bool isOpen() const {
        return file.is_open();
    }

    void displayContents() {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }

    ~FileReader() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    FileReader reader("example.txt");
    if (reader.isOpen()) {
        reader.displayContents();
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}
