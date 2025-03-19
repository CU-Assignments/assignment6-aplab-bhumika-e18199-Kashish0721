#include <iostream>
#include <stack>
using namespace std;

// Structure for a Node in BST
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function for Iterative Inorder Traversal of a BST
void inorderTraversal(Node* root) {
    stack<Node*> stk;
    Node* current = root;
    
    // Traverse the tree
    while (current != nullptr || !stk.empty()) {
        // Reach the leftmost node of the current node
        while (current != nullptr) {
            stk.push(current);
            current = current->left;
        }

        // Current must be NULL at this point
        current = stk.top();
        stk.pop();
        
        cout << current->data << " ";  // Visit the node
        
        // Visit the right subtree
        current = current->right;
    }
}

// Helper function to insert a new node into the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    Node* root = nullptr;

    // Inserting nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Performing the Iterative Inorder Traversal
    cout << "Inorder Traversal (Iterative): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
