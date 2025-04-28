#include <iostream>
#include <vector>
using namespace std;

class Animal {
public:
    virtual void makeSound() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void makeSound() const override {
        cout << "Woof woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        cout << "Meow!" << endl;
    }
};

class Cow : public Animal {
public:
    void makeSound() const override {
        cout << "Moo!" << endl;
    }
};

int main() {
    vector<Animal*> animals;
    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());

    for (const Animal* animal : animals) {
        animal->makeSound();
    }

    for (Animal* animal : animals) {
        delete animal;
    }
    return 0;
}
