#include <iostream>

using namespace std;

class vehicle{
public:
    string model;
    int rent;
    string type;

    vehicle(string m = "", int r = 0, string t = "") : model(m), rent(r), type(t) {}

    void showVehicleDetails(){
        cout << "Vehicle Model: " << model << "\nRent: " << rent << "\nRequired License: " << type << endl;
    }
};

class user{
private:
    int id;
    int age;
    int number;
    string License;
    vehicle* Vehicle;

public:
    user(int _id, int _age, int num, string l) : id(_id), age(_age), number(num), License(l), Vehicle(nullptr) {}

    ~user(){
        delete Vehicle;
    }

    void updateDetails(int _id, int _age, int num, string l){
        id = _id;
        age = _age;
        number = num;
        License = l;
    }

    void registerVehicle(vehicle* v){
        if (License != v->type) {
            cout << "Not eligible for this vehicle! You need a " << v->type << " license.\n";
            return;
        }

        if (Vehicle) delete Vehicle;  
        Vehicle = new vehicle(*v); 

        cout << "Vehicle rented successfully: " << Vehicle->model << endl;
    }

    void showDetails(){
        cout << "\nUser Details:\n";
        cout << "ID: " << id << "\nAge: " << age << "\nNumber: " << number << "\nLicense Type: " << License << endl;

        if (Vehicle) {
            cout << "\n Rented Vehicle Details:\n";
            Vehicle->showVehicleDetails();
        } else {
            cout << "No Vehicle Registered\n";
        }
    }
};

int main(){
    int id, age, number;
    string l;

    cout << "Enter Your Details:\n";
    cout << "ID: ";
    cin >> id;
    cout << "Age: ";
    cin >> age;
    cout << "Number: ";
    cin >> number;

    do{
        cout << "License (beginner | intermediate | full) {Case sensitive - type exactly}: ";
        cin >> l;
        if (l != "beginner" && l != "intermediate" && l != "full") {
            cout << "Invalid input! Please type exactly as given.\n";
        }
    }while (l != "beginner" && l != "intermediate" && l != "full");

    user user1(id, age, number, l);

    vehicle* vehicles[3];
    vehicles[0] = new vehicle("Toyota Corolla", 3000, "beginner");
    vehicles[1] = new vehicle("Honda Civic", 4000, "intermediate");
    vehicles[2] = new vehicle("BMW X5", 7000, "full");

    cout << "\nAvailable Vehicles:\n";
    for (int i = 0; i < 3; i++){
        cout << i + 1 << ". ";
        vehicles[i]->showVehicleDetails();
        cout << "------------------\n";
    }

    int choice;
    do{
        cout << "Enter the number of the vehicle you want to rent (1-3): ";
        cin >> choice;
        if (choice < 1 || choice > 3) {
            cout << "Invalid choice! Please enter a number between 1 and 3.\n";
        }
    }while (choice < 1 || choice > 3);

    user1.registerVehicle(vehicles[choice - 1]);

    user1.showDetails();

    for (int i = 0; i < 3; i++){
        delete vehicles[i];
    }

    return 0;
}

