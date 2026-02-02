// BinaryTree.h
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector> // For STL classes

// Node class definition
class Node {
public:
    int id;
    int value; // Weight of the node
    Node* left;
    Node* right;

    Node(int id, int value) : id(id), value(value), left(nullptr), right(nullptr) {}
};

// BinaryTree class definition
class BinaryTree {
public:
    Node *root;
    int greatestIDEver;

    BinaryTree();
    ~BinaryTree();

    // Function prototypes
    double getSubtreeWeight(int id);
    void enumerateBFS();
    Node* getNodeById(int id);
    int getLevelById(int id);
    int getLeftmostRightmostDistance();
    int getFarthestLeafId();
    int getClosestLeafId();
    void changeRoot(int newRootId);
    void addNode(Node* parent, int value, bool isLeft);
    void removeNode(int id);
    void printTreeInOrder();
    // YOU MAY ADD HELPER FUNCTIONS
    #ifdef USE_STUDENT_DESTRUCTOR_IMPL
    void emptyHelper(Node *&t);
    #endif
    #ifdef USE_STUDENT_GETNODEBYID_IMPL
    Node* getNodeHelper(int id, Node *ptr);
    #endif
    #ifdef USE_STUDENT_GETFARTHESTLEAFID_IMPL
    std::vector<int> getFarthestLeafIdHelper(Node *ptr);
    #endif
    #ifdef USE_STUDENT_GETCLOSESTLEAFID_IMPL
    std::vector<int> getClosestLeafIdHelper(Node *ptr);
    #endif
};

#endif // BINARYTREE_H