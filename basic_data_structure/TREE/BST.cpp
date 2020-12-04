/**
 * Binary Search Tree - BST implementation.
 * This is a simple implementation of BST.
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */
#include<bits/stdc++.h>

using namespace std;

typedef int Key;

class BST {
  public:
    struct Node {
      Key key;
      int index;
      Node* left;
      Node* right;

      Node(Key key, int index) {
        this->key = key;
        this->index = index;
        this->left = NULL;
        this->right = NULL;
      }
    };

    typedef Node* link;

  private:
    void printTree(link tree, int height) {
      if (tree == NULL) {
        for (int i = 0; i < height; ++i) cout << "  ";
        cout << "* " << endl;
        return;
      }

      printTree(tree->right, height + 1);
      for (int i = 0; i < height; ++i) cout << "  ";
      cout << tree->key << endl;
      printTree(tree->left, height + 1);
    }

    link leftmostNode(link tree) {
      if (tree->left != NULL) return leftmostNode(tree->left);
      return tree;
    }

    void insert(link& tree, Key key, int index) {
      if (tree == NULL) {
        tree = new Node(key, index);
        return;
      }

      if (key < tree->key) insert(tree->left, key, index);
      if (key > tree->key) insert(tree->right, key, index);
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

    void printTree() {
      this->printTree(root, 0);
    }

    void insert(Key key, int index) {
      this->insert(root, key, index);
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

        root->key = currentNode->key;

        root->right = erase(root->right, root->key);
      }

      return root;
    }

    void abolish() {
      this->abolish(root);
    }

    int find(Key key) {
      return this->find(root, key);
    }
};

int main() {
  freopen("BST.txt", "r+", stdin);
  freopen("BST.out", "w+", stdout);

  BST tree;
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    int u; cin >> u;
    tree.insert(u, i);
  }

  tree.printTree();

  int x; cin >> x;
  cout << "Deleted node contains " << x << endl;
  tree.root = tree.erase(tree.root, x);
  tree.printTree();

  tree.abolish();
  return 0;
}
