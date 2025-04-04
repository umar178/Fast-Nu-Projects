#include <iostream>
#include <string>

using namespace std;

const int MAX_PERMISSIONS = 5;
const int MAX_ASSIGNMENTS = 10;
const int MAX_STUDENTS = 10;
const int MAX_PROJECTS = 2;

int calculatePasswordHash(const string& password) {
    int hash = 5381;
    for (char c : password) {
        hash = hash * 33 + c;
    }
    return hash;
}

class User {
protected:
    string name;
    string id;
    string email;
    int hashedPassword;
    string permissions[MAX_PERMISSIONS];
    int permissionCount;

public:
    User(string n, string i, string e, string p, string perms[], int permCount) 
        : name(n), id(i), email(e), permissionCount(permCount) {
        hashedPassword = calculatePasswordHash(p);
        for (int i = 0; i < permCount; i++) {
            permissions[i] = perms[i];
        }
    }

    bool authenticate(string password) {
        return calculatePasswordHash(password) == hashedPassword;
    }

    bool hasPermission(string perm) {
        for (int i = 0; i < permissionCount; i++) {
            if (permissions[i] == perm) return true;
        }
        return false;
    }

    virtual void display() {
        cout << "Name: " << name << "\nID: " << id << "\nEmail: " << email << "\nPermissions: ";
        for (int i = 0; i < permissionCount; i++) {
            cout << permissions[i] << " ";
        }
        cout << endl;
    }

    bool performAction(string action, string password) {
        if (!authenticate(password)) {
            cout << "Authentication failed!" << endl;
            return false;
        }
        if (!hasPermission(action)) {
            cout << "Permission denied!" << endl;
            return false;
        }
        cout << "Action '" << action << "' performed successfully" << endl;
        return true;
    }
};

class Student : public User {
private:
    int assignments[MAX_ASSIGNMENTS];
    int assignmentCount;

public:
    Student(string n, string i, string e, string p) 
        : User(n, i, e, p, new string[1]{"submit assignment"}, 1), assignmentCount(0) {
        for (int i = 0; i < MAX_ASSIGNMENTS; i++) assignments[i] = 0;
    }

    void display() override {
        cout << "STUDENT DETAILS\n";
        User::display();
        cout << "Assignments: ";
        for (int i = 0; i < assignmentCount; i++) {
            cout << (assignments[i] ? "Submitted" : "Pending") << " ";
        }
        cout << endl;
    }

    void addAssignment() {
        if (assignmentCount < MAX_ASSIGNMENTS) {
            assignments[assignmentCount++] = 0;
        }
    }

    bool submitAssignment(int num, string password) {
        if (!performAction("submit assignment", password)) return false;
        if (num < 1 || num > assignmentCount) {
            cout << "Invalid assignment number!" << endl;
            return false;
        }
        assignments[num-1] = 1;
        cout << "Assignment " << num << " submitted" << endl;
        return true;
    }
    
    string getName(){
    	return name;
	}
};

class TA : public Student {
private:
    Student* students[MAX_STUDENTS];
    int studentCount;
    string projects[MAX_PROJECTS];
    int projectCount;

public:
    TA(string n, string i, string e, string p) 
        : Student(n, i, e, p), studentCount(0), projectCount(0) {
        permissions[permissionCount++] = "view projects";
        permissions[permissionCount++] = "manage_students";
    }

    void display() override {
        cout << "TEACHING ASSISTANT DETAILS\n";
        User::display();
        cout << "Managing " << studentCount << " students\n";
        cout << "Projects: ";
        for (int i = 0; i < projectCount; i++) {
            cout << projects[i] << " ";
        }
        cout << endl;
    }

    bool addStudent(Student* s, string password) {
        if (!performAction("manage_students", password)) return false;
        if (studentCount >= MAX_STUDENTS) {
            cout << "Cannot manage more students!" << endl;
            return false;
        }
        students[studentCount++] = s;
        cout << "Added student " << s->getName() << endl;
        return true;
    }

    bool addProject(string name, string password) {
        if (!performAction("view projects", password)) return false;
        if (projectCount >= MAX_PROJECTS) {
            cout << "Cannot take more projects!" << endl;
            return false;
        }
        projects[projectCount++] = name;
        cout << "Added project " << name << endl;
        return true;
    }
};

class Professor : public User {
public:
    Professor(string n, string i, string e, string p) 
        : User(n, i, e, p, new string[2]{"assign projects", "full_lab_access"}, 2) {}

    void display() override {
        cout << "PROFESSOR DETAILS\n";
        User::display();
    }

    bool assignProject(TA* ta, string name, string password) {
        if (!performAction("assign projects", password)) return false;
        return ta->addProject(name, password);
    }
};

int main() {
	cout << "A2 - Q4 - 24K-0880 - Muhammad Umer Karim" << endl;
    Student s("Umar", "0880", "Umar@school.edu", "22");
    TA ta("Akbar", "0696", "Akbar@school.edu", "333");
    Professor p("Zahid", "0543", "Zahid@school.edu", "55555");

    s.addAssignment();
    s.addAssignment();
    s.submitAssignment(1, "22");

    ta.addStudent(&s, "333");
    p.assignProject(&ta, "Quantum Research", "55555");

    cout << "\n";
    s.display();
    cout << "\n";
    ta.display();
    cout << "\n";
    p.display();

    return 0;
}

