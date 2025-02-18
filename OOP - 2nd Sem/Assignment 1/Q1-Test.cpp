#include<iostream>
#include<array> 

using namespace std;

class skill{
	public:
		int id;
		int name;
		string description;
		
		void showSkillDetails(){
			cout<<"Skill Details: "<<endl<<"Name: "<<name<<endl<<"ID: "<<id<<endl<<"Description: "<<description<<endl;
		}
		
		void updateSkillDescription(string newDescription){
			description = newDescription;
		}
};

class sport{
	public:
		int id;
		string name;
		string description;
		skill requiredSkills[];
		
		void addSkill(skill s){
			
		}
		
		void removeSkill(skill s){
			
		}
};

class student{
	public:
		int id;
		string name;
		int age;
		string* Interest;
		mentor Mentor;
		
		student(int _id, string _name, int _age, string* _interest) : id(_id), name(_name), age(_age), *Interest(*_interest){}
		
		void registerForMentorship(mentor m){
			
		}
		
		void viewMentorDetails(){
			cout<<"Mentor Details for "<<name<<": "<<endl<<"Name: "<<mentor.name<<endl<<"ID: "<< mentor.id<<endl<<"Expertise: "<<mentor.expertise<<endl;
		}
		
		void UpdateSportsInterest(sport s){
			
		}
};

class mentor{
	public:
		int id;
		string name;
		string expertise;
		int max;
		student Assigned_Students[];
		
		void assignLearner(student s){
			if(sizeof(Assigned_Students)/sizeof(Assigned_Students[0])<max){
					for(auto i: Assigned_Students){
						if(Assigned_Students[i] == NULL){
							Assigned_Students[i] = s;
							break;
						}
					}
				}
			}
			else{
				cout<<"Mentor's limit reached.";
			}
		}
		
		void removeLearner(student s){
			for(auto i: Assigned_Students){
				if(Assigned_Students[i] == s){
					Assigned_Students[i] = NULL;
				}
			}
		}
		
		void viewLearner(){
			
		}
		
		void provideGuidance(){
			
		}
};


