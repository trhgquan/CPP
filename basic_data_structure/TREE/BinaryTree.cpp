/**
 * This program implement a Binary Tree,
 * with insert, delete and search.
 */
#include<iostream>
#include<queue>
using namespace std;

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Create a node
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Level Order Traversal (LOT), or, Breadth First Traversal (BFT)
Node* search(Node* root, int key) {
    if (root == NULL) return NULL;
    queue<Node*> q;
    Node* out = NULL;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->key == key) out = temp;
        else {
            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }
    }
    return out;
}

// Insertion by finding the first vacant node in a BFT (LOT) fashion
void insert(Node** root, int key) {
    // Check if the tree is empty
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    // Create a new node
    Node* newNode = createNode(key);
    queue<Node*> q;
    q.push(*root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Check the left
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else q.push(temp->left);

        // Check the right
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else q.push(temp->right);
    }
}

// Set extreme right node to null
void setExtremerRightToNull(Node* root, Node* extremeRight) {
    queue<Node*>q;
    Node* temp;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->left == extremeRight) {
            temp->left = NULL;
            return;
        } else q.push(temp->left);
        if (temp->right == extremeRight) {
            temp->right = NULL;
            return;
        } else q.push(temp->right);
    }
}

// Delete a node
void deleteNode(Node* root, int key) {
    Node* nodeToDelete = search(root, key);
    if (nodeToDelete != NULL) {
        queue<Node*> q;
        Node* temp;
        q.push(root);

        while (!q.empty()) {
            temp = q.front();
            q.pop();

            if (temp->left != NULL) q.push(temp->left);
            if (temp->right != NULL) q.push(temp->right);
        }

        int keyAtDeepestRight = temp->key;
        // Look for a node in the tree that points at the extreme right
        setExtremerRightToNull(root, temp);
        // Delete the node
        nodeToDelete->key = keyAtDeepestRight;
    }
}

// Print the tree
void printTree(Node* root) {
    cout << root->key << endl;
    cout << root->left->key << endl;
    cout << root->right->key << endl;
    cout << root->left->left->key << endl;
    cout << root->left->right->key << endl;
    cout << root->right->left->key << endl;
}

int main() {
    // Insertion
    Node* root = NULL;
    for (int i = 1; i <= 6; ++i)
        insert(&root, i);
    printTree(root);

    // Searching
    Node* node = search(root, 3);
    if (node != NULL)
        cout << "found" << endl;
    else cout << "not found" << endl;

    // Deleting
    deleteNode(root, 3);
    printTree(root);

    return 0;
}
