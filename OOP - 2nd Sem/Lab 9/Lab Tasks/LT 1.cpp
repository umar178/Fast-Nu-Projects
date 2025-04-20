#include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    string getName() { return name; }
    int getAge() { return age; }
    void setName(string n) { name = n; }
    void setAge(int a) {
        if(a >= 0)
            age = a;
    }
    void displayInfo() {
        cout << "Name: " << name << endl << "Age: " << age << endl;
    }
};

int main() {
    Person person("Mr. Maseem", 25);
    person.displayInfo();

    person.setName("Mr. Abdullah");
    person.setAge(24);
    person.displayInfo();
    return 0;
}
