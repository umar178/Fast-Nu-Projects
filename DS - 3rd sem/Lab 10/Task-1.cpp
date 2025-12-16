#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkHeight(TreeNode* root) {
    if (!root) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1; 

    return max(leftHeight, rightHeight) + 1;
}

bool isSystemBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main() {
    TreeNode* balancedRoot = new TreeNode(1);
    balancedRoot->left = new TreeNode(2);
    balancedRoot->right = new TreeNode(3);
    balancedRoot->left->left = new TreeNode(4);
    balancedRoot->left->right = new TreeNode(5);

    TreeNode* unbalancedRoot = new TreeNode(1);
    unbalancedRoot->left = new TreeNode(2);
    unbalancedRoot->left->left = new TreeNode(3);
    unbalancedRoot->left->left->left = new TreeNode(4);

    cout << "Balanced Tree is balanced? "
         << (isSystemBalanced(balancedRoot) ? "YES" : "NO") << endl;

    cout << "Unbalanced Tree is balanced? "
         << (isSystemBalanced(unbalancedRoot) ? "YES" : "NO") << endl;

    return 0;
}

