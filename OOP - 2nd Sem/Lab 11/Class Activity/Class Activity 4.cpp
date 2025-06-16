#include "iostream"
using namespace std;

int main(){
    cout << "Start " << endl;

    try {
        cout << "Inside try block" << endl;
        throw 20;
        cout << "This will not execute";
    }
    catch (int i) {
        cout << "Caught an exception -- value is: ";
        cout << i << endl;
    }
    cout << "End";
    return 0;
}