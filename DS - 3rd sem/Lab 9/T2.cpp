#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

Node* findMin(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int data) {
    if(root == NULL)
        return root;

    if(data < root->data)
        root->left = deleteNode(root->left, data);

    else if(data > root->data)
        root->right = deleteNode(root->right, data);

    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool search(Node* root, int key) {
    if(root == NULL)
        return false;
    if(root->data == key)
        return true;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int choice, id;

    while(true) {
        cout << "\n--- Patient BST Menu ---\n";
        cout << "1. Insert Patient ID\n2. Search Patient ID\n3. Delete Patient ID\n4. Display Inorder\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                root = insert(root, id);
                cout << "Inorder after insertion: ";
                inorder(root);
                cout << endl;
                break;

            case 2:
                cout << "Enter Patient ID to search: ";
                cin >> id;
                if(search(root, id)) cout << "Record EXISTS\n";
                else cout << "Record NOT found\n";
                break;

            case 3:
                cout << "Enter Patient ID to delete: ";
                cin >> id;
                root = deleteNode(root, id);
                cout << "Inorder after deletion: ";
                inorder(root);
                cout << endl;
                break;

            case 4:
                inorder(root);
                cout << endl;
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid Choice!\n";
        }
    }
}

