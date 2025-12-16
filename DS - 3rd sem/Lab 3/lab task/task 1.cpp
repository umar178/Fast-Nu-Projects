#include<iostream>
using namespace std;

class node{
	public:
		int roll;
		string name;
		string dep;
		node * next;
		
		node(){
			next = NULL;
		}
		
		node(int r, string n, string d){
			roll = r;
			dep = d;
			name = n;
			next = NULL;
		}
};

class list{
	public:
		node * head;
		
		list(){
			head = NULL;
		}
		
		void addAtEnd(node * n){
			node * temp = head;
			n->next = NULL;
			
			if(head == NULL){
				head = n;
				return;
			}
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			
			temp->next = n;
		}
		
		void deleteByID(int id) {
		    node *curr = head;
		    node *prev = NULL;
		
		    while (curr != NULL) {
		        if (curr->roll == id) {
		            if (prev == NULL) {
		                head = curr->next;
		            } else {
		                prev->next = curr->next;
		            }
		            delete curr;
		            return;
		        }
		        prev = curr;
		        curr = curr->next;
		    }
		}
		
		void display(){
			node * temp = head;
			
			while(temp != NULL){
				cout<< temp->roll <<" "<< temp->name << " " << temp->dep << endl;
				temp = temp->next;
			}
		}
};

int main(){
	node *new_n1 = new node(1, "umar", "cs");
	node *new_n2 = new node(2, "akbar", "cs");
	node *new_n3 = new node(3, "wahab", "cs");
	node *new_n4 = new node(4, "ali", "cs");
	
	list students;
	students.addAtEnd(new_n1);
	students.addAtEnd(new_n2);
	students.addAtEnd(new_n3);
	students.addAtEnd(new_n4);
	cout<<"4 records added: "<<endl;
	students.display();
	students.deleteByID(2);
	cout<<endl<<"1 record deleted: "<<endl;
	students.display();
}
