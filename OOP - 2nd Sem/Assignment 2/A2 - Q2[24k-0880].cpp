#include <iostream>
#include <string>
using namespace std;

class Ghost {
public:
	string name;
    int scareLevel;
    Ghost(string n, int s) : name(n), scareLevel(s) {}
    virtual void haunt() const = 0;
    int getScareLevel() const { return scareLevel; }

    friend ostream& operator<<(ostream& os, const Ghost& g) {
        os << "Ghost: " << g.name << ", Scare Level: " << g.scareLevel;
        return os;
    }

    virtual ~Ghost() {}
};

class Poltergeist : public Ghost {
public:
    Poltergeist(string n, int s) : Ghost(n, s) {}
    
    void haunt() const override {
        cout << name << " moves objects violently!" << endl;
    }

    Poltergeist operator+(const Ghost& other) {
        return Poltergeist("Hybrid of " + name + " & " + other.name, scareLevel + other.scareLevel);
    }
};

class Banshee : public Ghost {
public:
    Banshee(string n, int s) : Ghost(n, s) {}
    void haunt() const override {
        cout << name << " screams loudly!" << endl;
    }
};

class ShadowGhost : public Ghost {
public:
    ShadowGhost(string n, int s) : Ghost(n, s) {}
    void haunt() const override {
        cout << name << " whispers creepily..." << endl;
    }
};

class ShadowPoltergeist : public Ghost {
    ShadowGhost shadowGhost;
    Poltergeist poltergeist;

public:
    ShadowPoltergeist(string n, int s1, int s2)
        : Ghost(n, s1 + s2), shadowGhost(n + "_shadow", s1), poltergeist(n + "_poltergeist", s2) {}

    void haunt() const override {
        shadowGhost.haunt();
        poltergeist.haunt();
    }
};

class Visitor {
    string name;
    int bravery;

public:
    Visitor(string n, int b) : name(n), bravery(b) {}

    string getName() const { return name; }
    int getBravery() const { return bravery; }

    void reactTo(int scare) const {
        if (scare < bravery - 2)
            cout << name << " laughs at the ghost!" << endl;
        else if (scare > bravery + 2)
            cout << name << " screams and runs away!" << endl;
        else
            cout << name << " is shaking with fear..." << endl;
    }
};

class HauntedHouse {
    string houseName;
    Ghost* ghosts[10];
    int count;

public:
    HauntedHouse(string name) : houseName(name), count(0) {}

    void addGhost(Ghost* g) {
        if (count < 10) ghosts[count++] = g;
    }

    friend void visit(Visitor* v[], int vCount, HauntedHouse& h) {
        cout << "\n--- Visiting " << h.houseName << " ---\n";
        for (int i = 0; i < vCount; ++i) {
            cout << v[i]->getName() << " enters...\n";
            for (int j = 0; j < h.count; ++j) {
                h.ghosts[j]->haunt();
                v[i]->reactTo(h.ghosts[j]->getScareLevel());
            }
        }
    }

    ~HauntedHouse() {
        for (int i = 0; i < count; ++i)
            delete ghosts[i];
    }
};

int main() {
    cout << "A2 - Q2 - 24K-0880 - Muhammad Umer Karim" << endl;

    HauntedHouse hh1("Ghost House");

    hh1.addGhost(new Poltergeist("Polty", 5));
    hh1.addGhost(new Banshee("Bansha", 7));
    hh1.addGhost(new ShadowGhost("Shadowy", 6));

    Visitor* visitors[3] = {
        new Visitor("Alice", 3),
        new Visitor("Bob", 6),
        new Visitor("Charlie", 9)
    };

    visit(visitors, 3, hh1);

    for (int i = 0; i < 3; ++i)
        delete visitors[i];

    return 0;
}

