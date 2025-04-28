#include <iostream>
#include <fstream>
using namespace std;

class FileAppender {
private:
    ofstream file;
public:
    FileAppender(string filename) {
        file.open(filename, ios::app);
        if (!file) {
            cout << "Failed to open file!" << endl;
            exit(1);
        }
    }

    void append(string text) {
        file << text;
    }

    ~FileAppender() {
        file.close();
        cout << "Data written successfully." << endl;
    }
};

int main() {
    FileAppender myFile("data.txt");
    myFile.append("This line is appended using the open() method.\n");
    return 0;
}
