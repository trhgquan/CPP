#include<iostream>
#include<queue>
#include<string>
using namespace std;

// Node struct
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

// Insert a node
void insert(Node** root, int key) {
    // Check if the tree is empty
    // If the tree is empty, we create the root node
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    Node* newNode = createNode(key);
    queue<Node*>q;
    q.push(*root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // If left is empty, insert the node into left.
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else q.push(temp->left);

        // If right is empty, insert the node into right
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else q.push(temp->right);
    }
}

// Breadth First Traversal (BFT) or Level Order Traversal (LOT)
void BFTraversal(Node* root) {
    // If the root node is NULL, we don't do traversal.
    if (root == NULL) return;

    // Basically this is a BFS.
    // So we will start with a queue.
    queue<Node*> q;

    // Always insert the first (root) node.
    q.push(root);

    // Whle the queue is not empty, do traversal
    while (!q.empty()) {
        // Get the front item of the queue, then pop it out of the queue
        Node* node = q.front(); q.pop();

        // And output that node.
        cout << node->key << ' ';

        // Now we check, if the left item is not NULL, push it to the queue
        if (node->left != NULL)
            q.push(node->left);

        // If the right item is not NULL, push it to the queue too.
        if (node->right != NULL)
            q.push(node->right);
    }
}

// Depth First Traversal - inorder
void DFTraversal_IO(Node* root) {
    // If the root is NULL, we don't do traversal
    if (root == NULL) return;

    // Travel to the left, recursively.
    DFTraversal_IO(root->left);

    // Print that node
    cout << root->key << ' ';

    // Travel to the right, recursively.
    DFTraversal_IO(root->right);
}

// Depth First Traversal - preorder
void DFTraversal_PreO(Node* root) {
    // If the root is NULL, we don't do traversal.
    if (root == NULL) return;

    cout << root->key << ' ';

    // Travel to the left, recursively.
    DFTraversal_PreO(root->left);

    // Travel to the right, recursively.
    DFTraversal_PreO(root->right);
}

// Depth First Traversal - postorder
void DFTraversal_PosO(Node* root) {
    // If the root is NULL, we don't do traversal.
    if (root == NULL) return;

    // Travel to the left, recursively.
    DFTraversal_PosO(root->left);

    // Travel to the right, recursively.
    DFTraversal_PosO(root->right);

    // Print the node.
    cout << root->key << ' ';
}

int main() {
    // For example, we will look at this tree
    /**
    	    1           LEVEL 1
	     /     \
	    2       3       LEVEL 2
      /   \   /   \
     4     5 6     7    LEVEL 3
    */
    Node* root = NULL;
    for (int i = 1; i <= 7; ++i)
        insert(&root, i);

    // Using BFT Traversal:
    // cout << "Breadth First Traversal:" << endl;
    // BFTraversal(root);

    // Using DFT inorder Traversal:
    // cout << "Depth First Traversal - inorder:" << endl;
    // DFTraversal_IO(root);

    // Using DFT preorder Traversal
    // cout << "Depth First Traversal - preorder:" << endl;
    // DFTraversal_PreO(root);

    // Using DFT postorder Traversal
    // cout << "Depth First Traversal - postorder:" << endl;
    // DFTraversal_PosO(root);
}
