#include<iostream>

using namespace std;

class skill{
	public:
		int id;
		string name;
		string description;
		
		skill() : id(0), name(""), description("") {}
		skill(int _id, string _name, string _description) : id(id), name(_name), description(_description){};
		
		void showSkillDetails(){
			cout<<"Skill Details: "<<endl<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Description: "<<description<<endl;
		}
		
		void updateSkillDescription(string newDescription){
			description = newDescription;
		}
		
		bool operator==(const skill& other) const {
        	return id == other.id; 
   		}
};

class sport{
	public:
		int id;
		string name;
		string description;
		skill *requiredSkills;
		int s_size;
		
		sport(int _id, string _name, string _description, skill *_skills, int size) : id(_id), name(_name), description(_description), s_size(size){
			requiredSkills = new skill[size];
			for(int i = 0; i<size; i++){
				requiredSkills[i] = _skills[i];
			}
		}
		
		void addSkill(skill s){
			skill* temp = new skill[s_size+1];
			for(int i = 0; i<s_size; i++){
				temp[i] = requiredSkills[i];
			}
			temp[s_size] = s;
			s_size++;
			delete[] requiredSkills;
			requiredSkills = temp;
			delete[] temp;
		}
		
		//for debugging - by Umar
		void displaySkills() {
	        for (int i = 0; i < s_size; i++) {
	            cout << "Skill " << i + 1 << ": " << requiredSkills[i].name << endl;
	        }
    	}
		
		void removeSkill(skill s) {
	        int index = -1;
	        for (int i = 0; i < s_size; i++) {
	            if (requiredSkills[i] == s) {
	                index = i;
	                break;
	            }
	        }
	        if (index == -1) {
	            cout << "No such skill found" << endl;
	            return;
	        }
	
	        skill* temp = new skill[s_size - 1];
	        for (int i = 0, j = 0; i < s_size; i++) {
	            if (i != index) {
	                temp[j++] = requiredSkills[i];
	            }
	        }
	
	        delete[] requiredSkills;
	        requiredSkills = temp;
	        s_size--;
   		}
		
		~sport() {
        	delete[] requiredSkills;
    	}
};

class mentor; 

class student {
public:
    int id;
    string name;
    int age;
    string* Interest;
    int interestCount;
    mentor* Mentor;

    student(int _id, string _name, int _age, int interestSize, string *_interest) : id(_id), name(_name), age(_age) {
        Interest = new string[interestSize];
        interestCount = interestSize;
        for (int i = 0; i < interestCount; i++) {
            Interest[i] = _interest[i]; 
        }
        Mentor = NULL;
    }

    ~student() {
        delete[] Interest; 
    }

    void registerForMentorship(mentor* m);

    void viewMentorDetails();
};

class mentor {
public:
    int id;
    string name;
    string expertise;
    int max;
    student** Assigned_Students; 
    int studentCount;

    mentor(int _id, string _name, string _expertise, int _max) : id(_id), name(_name), expertise(_expertise), max(_max) {
        Assigned_Students = new student*[max];
        studentCount = 0;
        for (int i = 0; i < max; i++) {
            Assigned_Students[i] = NULL;
        }
    }

    ~mentor() {
    	for(int i = 0; i<studentCount; i++){
    		delete Assigned_Students[i];
		}
        delete[] Assigned_Students;
    }

    void assignLearner(student* s) {
        if (studentCount < max) {
            for (int i = 0; i < max; i++) {
                if (Assigned_Students[i] == NULL) {
                    Assigned_Students[i] = s;
                    s->Mentor = this;
                    studentCount++;
                    cout << s->name << " assigned to mentor " << name << endl;
                    return;
                }
            }
        }
        cout << "Mentor's limit reached.\n";
    }

    void removeLearner(student* s) {
        for (int i = 0; i < max; i++) {
            if (Assigned_Students[i] == s) {
                Assigned_Students[i] = NULL;
                s->Mentor = NULL;
                studentCount--;
                cout << s->name << " removed from mentor " << name << endl;
                return;
            }
        }
    }

    void viewLearners() {
        cout << "Mentor " << name << "'s assigned students:\n";
        for (int i = 0; i < max; i++) {
            if (Assigned_Students[i] != NULL) {
                cout << "Student: " << Assigned_Students[i]->name << endl;
            }
        }
    }
};

void student::registerForMentorship(mentor* m) {
    m->assignLearner(this);
    *Mentor = *m;
}

void student::viewMentorDetails(){
	if (Mentor) {
            cout << "Mentor Details for " << name << ":\n";
            cout << "Name: " << Mentor->name << "\nID: " << Mentor->id << "\nExpertise: " << Mentor->expertise << endl;
        } else {
            cout << name << " has no assigned mentor.\n";
        }
}

#include<iostream>

using namespace std;

int main() {
    int choice;
    skill skills[3] = {
        skill(1, "Dribbling", "Control the ball"),
        skill(2, "Shooting", "Hit the target"),
        skill(3, "Passing", "Deliver the ball to teammates")
    };

    sport football(1, "Football", "Team-based sport", skills, 3);
    
    mentor coach(1, "Umar", "Football Coach", 2);
    student *students[2];
    students[0] = new student(1, "Akbar", 20, 2, new string[2]{"Football", "Basketball"});
    students[1] = new student(2, "Saad", 21, 1, new string[1]{"Football"});
    
    do {
        cout << "\n===== Sports Management System =====\n";
        cout << "1. View Sport Details\n";
        cout << "2. Add Skill to Sport\n";
        cout << "3. Remove Skill from Sport\n";
        cout << "4. Register Student for Mentorship\n";
        cout << "5. View Mentor's Students\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Sport: " << football.name << "\nDescription: " << football.description << "\n";
                football.displaySkills();
                break;
            
            case 2: {
                int id;
                string name, desc;
                cout << "Enter skill ID: "; cin >> id;
                cout << "Enter skill name: "; cin >> name;
                cout << "Enter skill description: "; cin >> desc;
                football.addSkill(skill(id, name, desc));
                cout << "Skill added successfully!\n";
                break;
            }
            
            case 3: {
                int id;
                cout << "Enter skill ID to remove: "; cin >> id;
                for (int i = 0; i < football.s_size; i++) {
                    if (football.requiredSkills[i].id == id) {
                        football.removeSkill(football.requiredSkills[i]);
                        cout << "Skill removed successfully!\n";
                        break;
                    }
                }
                break;
            }
            
            case 4:
                cout << "Assigning " << students[0]->name << " to mentor...\n";
                students[0]->registerForMentorship(&coach);
                cout << "Student registered successfully!\n";
                break;
            
            case 5:
                coach.viewLearners();
                break;
            
            case 6:
                cout << "Exiting program...\n";
                break;
                
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);
    
    for (int i = 0; i < 2; i++) delete students[i];
    return 0;
}

