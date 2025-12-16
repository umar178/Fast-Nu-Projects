#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char name[30];
    Node *left, *right;
};

Node* createNode(char name[]) {
    Node* temp = new Node();
    strcpy(temp->name, name);
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(Node* root) {
    if(root != NULL) {
        cout << root->name << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->name << " ";
        inorder(root->right);
    }
}

void postorder(Node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->name << " ";
    }
}

Node* insertNode(Node* root, char name[]) {
    if(root == NULL) {
        cout << "Inserted as root\n";
        return createNode(name);
    }

    char choice;
    cout << "Insert to Left (l) or Right (r) of " << root->name << "? ";
    cin >> choice;

    if(choice == 'l')
        root->left = insertNode(root->left, name);
    else
        root->right = insertNode(root->right, name);

    return root;
}

int main() {
    Node* root = NULL;
    int n;
    char name[30];

    cout << "How many plant names to insert? ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter plant name: ";
        cin >> name;
        root = insertNode(root, name);

        cout << "\nPreorder: ";
        preorder(root);

        cout << "\nInorder: ";
        inorder(root);

        cout << "\nPostorder: ";
        postorder(root);
        cout << "\n-----------------------------\n";
    }

    return 0;
}

