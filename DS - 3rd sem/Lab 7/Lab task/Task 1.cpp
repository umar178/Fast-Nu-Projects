#include <iostream>
using namespace std;

struct Process {
    int id;
    int priority;
};

class Queue {
    Process arr[100];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return rear == 99;
    }

    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = p;
    }

    Process dequeue() {
        Process temp = {-1, -1};
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue.\n";
            return temp;
        }
        temp = arr[front++];
        if (front > rear) front = rear = -1;
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << "Process ID: " << arr[i].id << " | Priority: " << arr[i].priority << endl;
        }
    }
};

class Stack {
    Process arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(Process p) {
        if (isFull()) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = p;
    }

    Process pop() {
        Process temp = {-1, -1};
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return temp;
        }
        return arr[top--];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << "Process ID: " << arr[i].id << " | Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    Queue jobQueue;
    Stack highPriorityStack;

    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Process p;
        cout << "Enter Process ID: ";
        cin >> p.id;
        cout << "Enter Priority (1=Low, 2=Medium, 3=High): ";
        cin >> p.priority;
        jobQueue.enqueue(p);
    }

    cout << "\n--- Processes in Queue (Arrival Order) ---\n";
    jobQueue.display();

    cout << "\n--- Moving High Priority Jobs to Stack ---\n";
    while (!jobQueue.isEmpty()) {
        Process current = jobQueue.dequeue();
        if (current.priority == 3) {
            highPriorityStack.push(current);
            cout << "Moved to Stack (High Priority): Process " << current.id << endl;
        } else {
            cout << "Executing directly (Low/Medium): Process " << current.id << endl;
        }
    }

    cout << "\n--- Executing High Priority Jobs (Stack: LIFO Order) ---\n";
    while (!highPriorityStack.isEmpty()) {
        Process p = highPriorityStack.pop();
        cout << "Executing Process ID: " << p.id << " | Priority: " << p.priority << endl;
    }

    cout << "\nAll processes executed successfully.\n";
    return 0;
}

