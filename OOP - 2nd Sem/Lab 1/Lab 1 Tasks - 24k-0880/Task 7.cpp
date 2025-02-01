#include <iostream>
#include <string>
using namespace std;

int countVowels(string str) {
    int count = 0;
    for (char c : str) {
        char ch = toupper(c);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    return count;
}

int main() {
    string str = "Hello World";

    string upperStr = str;
    for (char &c : upperStr) {
        c = toupper(c);
    }

    int vowels = countVowels(str);

    string noSpaceStr = "";
    for (char c : str) {
        if (c != ' ') {
            noSpaceStr += c;
        }
    }

    cout << "Uppercase: " << upperStr << endl;
    cout << "Vowel count: " << vowels << endl;
    cout << "No spaces: " << noSpaceStr << endl;

    return 0;
}

