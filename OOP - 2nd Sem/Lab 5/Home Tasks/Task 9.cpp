#include <iostream>
#include <vector>
using namespace std;

class Subject {
public:
    string subjectName;
    Subject(string name) : subjectName(name) {}
};

class Professor {
private:
    string name;
    vector<Subject*> subjects;

public:
    Professor(string _name) : name(_name) {}

    void assignSubject(Subject* sub) {
        subjects.push_back(sub);
    }

    void displaySubjects() {
        cout << "Teacher: " << name << " teaches:\n";
        for (size_t i = 0; i < subjects.size(); i++) {
    		cout << "- " << subjects[i]->subjectName << endl;
		}
    }
};

int main() {
    Subject math("Mathematics"), science("Science"), history("History");
    Professor prof("Mr. Smith");

    prof.assignSubject(&math);
    prof.assignSubject(&science);
    prof.assignSubject(&history);

    prof.displaySubjects();
    return 0;
}

