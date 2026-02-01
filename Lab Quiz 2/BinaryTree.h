#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

class Node {
public:
    int id;
    int value;
    Node* left;
    Node* right;
    Node(int id, int value) : id(id), value(value), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    Node *root;
    int greatestIDEver;

    BinaryTree();
    ~BinaryTree();

    Node* getNodeById(int id);
    void addNode(Node* parent, int value, bool isLeft);
    
    // --- Quiz Questions ---
    void printTreePostOrder();
    void removeNode(int id);
    void buildPerfectTree(int* values, int size);
    void helperPost(Node* ptr);
    //Node* findParent(Node* ptr)
};


#endif // BINARYTREE_H