/**
 * AVL tree implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<bits/stdc++.h>

using namespace std;

typedef int Key;

class BST {
  private:
    struct Node {
      Key key;
      int index, nodes, height;
      Node* left;
      Node* right;

      Node(Key key, int index) {
        this->key = key;
        this->index = index;
        this->nodes = this->height = 1;
        this->left = NULL;
        this->right = NULL;
      }
    };

    typedef Node* link;

    int getHeight(link tree) {
      if (tree == NULL) return 0;
      return tree->height;
    }

    int getNodes(link tree) {
      if (tree == NULL) return 0;
      return tree->nodes;
    }

    link leftmostNode(link tree) {
      if (tree->left != NULL) return leftmostNode(tree->left);
      return tree;
    }

    link rightmostNode(link tree) {
      if (tree->right != NULL) return rightmostNode(tree->right);
      return tree;
    }

    void balancing(link& tree) {
      if (tree == NULL) return;

      if (getHeight(tree->left) - getHeight(tree->right) == 2) {
        if (getHeight(tree->left->left) < getHeight(tree->left->right))
          rotateLeft(tree->left);
        rotateRight(tree);
      }

      if (getHeight(tree->right) - getHeight(tree->left) == 2) {
        if (getHeight(tree->right->left) > getHeight(tree->right->right))
          rotateRight(tree->right);
        rotateLeft(tree);
      }
    }

    void updateHeight(link& tree) {
      if (tree->left != NULL) updateHeight(tree->left);
      if (tree->right != NULL) updateHeight(tree->right);

      tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
    }

    void printTree(link tree, int height) {
      if (tree == NULL) {
        for (int i = 0; i < height; ++i) cout << "  ";
        cout << "* " << endl;
        return;
      }

      printTree(tree->right, height + 1);

      for (int i = 0; i < height; ++i) cout << "  ";
      cout << tree->key << ":" << tree->height << endl;

      printTree(tree->left, height + 1);
    }

    void insert(link& tree, Key key, int index) {
      if (tree == NULL) {
        tree = new Node(key, index);
        return;
      }

      if (key < tree->key) insert(tree->left, key, index);
      if (key > tree->key) insert(tree->right, key, index);

      tree->height = max(getHeight(tree->left), getHeight(tree->right)) + 1;
      tree->nodes  = getNodes(tree->left) + getNodes(tree->right) + 1;

      balancing(tree);
    }

    void abolish(link tree) {
      if (tree->left != NULL) abolish(tree->left);
      if (tree->right != NULL) abolish(tree->right);

      delete tree;
    }

    int find(link tree, Key key) {
      if (tree != NULL) {
        if (tree->key == key) return tree->index;

        if (key < tree->key) return find(tree->left, key);
        return find(tree->right, key);
      }

      return -1;
    }

  public:
    link root;

    BST() {
      this->root = NULL;
    }

    int getHeight() {
      return this->getHeight(root);
    }

    int getNodes() {
      return this->getNodes(root);
    }

    void printTree() {
      this->printTree(root, 0);
    }

    void insert(Key key, int index) {
      this->insert(root, key, index);
    }

    void abolish() {
      this->abolish(root);
    }

    void rotateRight(link& tree) {
      link thisNode = tree->left;

      tree->left = thisNode->right;
      thisNode->right = tree;

      tree = thisNode;

      // Updating heights
      updateHeight(tree);
    }

    void rotateLeft(link& tree) {
      link thisNode = tree->right;

      tree->right = thisNode->left;
      thisNode->left = tree;

      tree = thisNode;

      // Update heightd
      updateHeight(tree);
    }

    int find(Key key) {
      return this->find(root, key);
    }

    link erase(link root, int key) {
      if (root == NULL) return root;

      if (root->key > key) root->left = erase(root->left, key);
      else if (root->key < key) root->right = erase(root->right, key);
      else {
        link currentNode;

        if (root->left == NULL) {
          currentNode = root->right;
          delete root;
          return currentNode;
        }

        if (root->right == NULL) {
          currentNode = root->left;
          delete root;
          return currentNode;
        }

        currentNode = leftmostNode(root->right);
        // currentNode = rightmostNode(root->left);

        root->key = currentNode->key;
        root->index = currentNode->index;

        root->right = erase(root->right, root->key);
        // root->left = erase(root->left, root->key);
      }

      updateHeight(root);
      balancing(root);

      return root;
    }

    void inorderTraversal(link root) {
      if (root == NULL) return;

      if (root->left != NULL) inorderTraversal(root->left);
      cout << root->key << ' ';
      if (root->right != NULL) inorderTraversal(root->right);
    }
};

int main() {
  freopen("AVL.txt", "r+", stdin);
  // freopen("AVL.out", "w+", stdout);

  BST tree;
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int u; cin >> u;
    tree.insert(u, i);
  }

  cout << "Inorder traversal: ";
  tree.inorderTraversal(tree.root);
  cout << endl;

  cout << "Tree before deleting.." << endl;
  tree.printTree();
  cout << "Position that " << k << " appears: " << tree.find(k) << endl;

  int x; cin >> x;
  tree.root = tree.erase(tree.root, x);
  cout << "Tree after deleting " << x << endl;
  tree.printTree();

  cout << "Position that " << k << " appears: " << tree.find(k) << endl;

  tree.abolish();
  return 0;
}
