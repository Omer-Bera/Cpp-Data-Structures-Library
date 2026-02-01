#include "BinaryTree.h"
#include <cmath> // For Q3 math

BinaryTree::BinaryTree() {
    root = NULL;
    greatestIDEver = 1;
}

static void deleteSubtreeRecursive(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteSubtreeRecursive(node->left);
    deleteSubtreeRecursive(node->right);
    delete node;
}
 
BinaryTree::~BinaryTree() {
    deleteSubtreeRecursive(this->root);
    this->root = nullptr;
}

static Node* findNodeRecursive_forGet(Node* node, int id) {
    if (node == nullptr) {
        return nullptr;
    }
    if (node->id == id) {
        return node;
    }
    // Search left subtree
    Node* leftResult = findNodeRecursive_forGet(node->left, id);
    if (leftResult != nullptr) {
        return leftResult;
    }
    // Search right subtree
    return findNodeRecursive_forGet(node->right, id);
}
 
Node* BinaryTree::getNodeById(int id) {
    return findNodeRecursive_forGet(this->root, id);
}

void BinaryTree::addNode(Node* parent, int value, bool isLeft) {
    int newId = greatestIDEver + 1;
    Node* newNode = new Node(newId, value);
    if (parent == NULL) {
        if (root == NULL) { root = newNode; greatestIDEver++; }
        else delete newNode;
    } else {
        if (isLeft && parent->left == NULL) {
            parent->left = newNode; greatestIDEver++;
        } else if (!isLeft && parent->right == NULL) {
            parent->right = newNode; greatestIDEver++;
        } else {
            delete newNode;
        }
    }
}

