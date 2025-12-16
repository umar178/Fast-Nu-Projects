#include<iostream>

using namespace std;

bool p(const string& s, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (s[left] != s[right]) {
        cout << "false\n";
        return false;
    }
    return p(s, left + 1, right - 1);
}

int main() {
    string s = "madam";
    if (p(s, 0, s.length() - 1)) {
        cout << "true\n";
    }
    return 0;
}
