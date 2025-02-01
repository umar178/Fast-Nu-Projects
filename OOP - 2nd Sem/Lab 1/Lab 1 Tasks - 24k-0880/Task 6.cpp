#include <iostream>
using namespace std;

bool isPerfect(int num) {
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
}

int main() {
    int num = 6;

    if (isPerfect(num)) {
        cout << num << " is a perfect number.";
    } else {
        cout << num << " is not a perfect number.";
    }

    return 0;
}
