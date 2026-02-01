#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <iomanip> // For printing doubles
#include <climits> // For INT_MAX/INT_MIN

// Note: Do not use 'using namespace std;' in your .cpp file.
// Use std:: directly (e.g., std::cout, std::vector).
#ifdef USE_STUDENT_CONSTRUCTOR_IMPL
/**
 * Constructor: Initializes an empty tree.
 * root should be nullptr.
 * greatestIDEver should be 1.
 */
BinaryTree::BinaryTree() {
    // YOUR CODE GOES HERE
    root = nullptr;
    greatestIDEver = 1;
}
#endif


#ifdef USE_STUDENT_DESTRUCTOR_IMPL
/**
 * Destructor: Frees all dynamically allocated memory.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
void BinaryTree::emptyHelper(Node *&ptr)
{
    if (ptr != nullptr)
    {
        emptyHelper(ptr->left);
        emptyHelper(ptr->right);
        delete ptr;
        ptr = nullptr;
    }
}
BinaryTree::~BinaryTree() {
    // YOUR CODE GOES HERE
    emptyHelper(root);
}

#endif


#ifdef USE_STUDENT_GETSUBTREEWEIGHT_IMPL
/**
 * Calculates the average weight of the subtree rooted at node `id`.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
double BinaryTree::getSubtreeWeight(int id) {
    // YOUR CODE GOES HERE
    double totalWeight = 0.0;
    Node* initialPoint = this->getNodeById(id);
    if(nullptr == initialPoint){
        return 0.0;
    }
    std::queue<Node*> q;
    q.push(initialPoint);
    int count = 0;
    while(!q.empty()){
        Node *current = q.front();
        Node *L = current->left;
        Node *R = current->right;
        totalWeight += current->value;
        if(L != nullptr)
            q.push(L);
        if(R != nullptr)
            q.push(R);
        q.pop();
        count += 1;
    }
    return totalWeight/count;
}
#endif


#ifdef USE_STUDENT_ENUMERATEBFS_IMPL
/**
 * Enumerates the node IDs in BFS order, printing them.
 * Output format: "id1 id2 id3 \n"
 */
void BinaryTree::enumerateBFS()
{
    if (root == nullptr)
    {
        return;
    }

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        std::cout << current->id << " ";
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    std::cout << std::endl;
}
#endif


#ifdef USE_STUDENT_GETNODEBYID_IMPL
/**
 * Finds and returns a pointer to the node with the given `id`.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
Node* BinaryTree::getNodeById(int id) {
    // YOUR CODE GOES HERE
    return getNodeHelper(id, root);
}

Node* BinaryTree::getNodeHelper(int id, Node *ptr){
    if(ptr == nullptr) return nullptr;
    if(id == ptr->id) return ptr;
    Node *result = getNodeHelper(id, ptr->left);
    if(result != nullptr) return result;
    else return getNodeHelper(id, ptr->right);
}

#endif


#ifdef USE_STUDENT_GETLEVELBYID_IMPL
/**
 * Finds the level of the node with the given `id`. Root is level 0.
 * (Hint: A BFS is a good way to find level)
 */
int BinaryTree::getLevelById(int id) {
    // YOUR CODE GOES HERE
    if(root == nullptr) return -1;
    if(root->id == id) return 0;
    std::queue<Node*> q;
    Node *current = root;
    int count = 0;
    int size = 0;
    q.push(current);
    while(!q.empty()){
        size = q.size();
        for(int i = 0; i < size; i ++){
            current = q.front();
            q.pop();
            if(current->id == id) return count;
            if(current->left != nullptr) q.push(current->left);
            if(current->right != nullptr) q.push(current->right);
        }
        count++;
    }
    return -1;
}
#endif


#ifdef USE_STUDENT_GETLEFTMORTRIGHTMOSTDISTANCE_IMPL
/**
 * Finds the distance between the leftmost and rightmost nodes.
 * (Hint: You can call this->getLevelById(id) on the nodes.)
 */
int BinaryTree::getLeftmostRightmostDistance() {
    // YOUR CODE GOES HERE
    if(root == nullptr) return 0;
    int leftSum = 0, rightSum = 0;
    Node *pivot = root;
    while (pivot->left != nullptr){
        pivot = pivot->left;
        leftSum++;
    }
    pivot = root;
    while (pivot->right != nullptr)
    {
        pivot = pivot->right;
        rightSum++;
    }
    return leftSum + rightSum;
}
#endif


#ifdef USE_STUDENT_GETFARTHESTLEAFID_IMPL
/**
 * Finds the ID of the *leftmost* leaf node farthest from the root.
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */


    int BinaryTree::getFarthestLeafId()
    // YOUR CODE GOES HERE
    {
        if (root == nullptr)
            return -1;
        return *(getFarthestLeafIdHelper(root).begin() + 1);
    }

    std::vector<int> BinaryTree::getFarthestLeafIdHelper(Node *ptr)
    {
        std::vector<int> result = {0, ptr->id};
        std::vector<int> left = {0, ptr->id};
        std::vector<int> right = {0, ptr->id};
        std::vector<int> tmp;

        if (ptr->left == nullptr && ptr->right == nullptr)
            return result;
        if (ptr->left != nullptr){
            tmp = getFarthestLeafIdHelper(ptr->left);
            *left.begin() = 1 + *tmp.begin();
            *(left.begin()+1) = *(tmp.begin()+1);
        }
        if(ptr->right!= nullptr){
            tmp = getFarthestLeafIdHelper(ptr->right);
            *right.begin() = 1 + *(tmp.begin());
            *(right.begin()+1) = *(tmp.begin() + 1);
        }
        if (*(right.begin()) > *(left.begin())){
            result[0] = *right.begin();
            result[1] = *(right.begin()+1);
        }
        else{
            result[0] = *(left.begin());
            result[1] = *(1+left.begin());
        }
        return result;
    }

#endif


#ifdef USE_STUDENT_GETCLOSESTLEAFID_IMPL
    /**
     * Finds the ID of the *leftmost* leaf node closest to the root.
     * (Hint: Define a recursive helper function *inside* this #ifdef block)
     */

    int BinaryTree::getClosestLeafId() {
    // YOUR CODE GOES HERE
    if(root == nullptr) return -1;
    if (root->left == nullptr && root->right == nullptr) return root->id;
    std::queue<Node *> q;
    Node *tmp;
    tmp = root;
    q.push(tmp);
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        if(tmp->left == nullptr){
            if (tmp->right == nullptr){
                return tmp->id;
            }
            else{
                q.push(tmp->right);
            }
        }
        else{
            q.push(tmp->left);
            if (tmp->right != nullptr)
            {
                q.push(tmp->right);
            }
        }
        
    }
    return -1;
    }

#endif

#ifdef USE_STUDENT_CHANGEROOT_IMPL
        /**
         * Changes the root of the tree to the node with `newRootId`.
         * Fails if the new root has 2 children.
         * (Hint: You can call this->getNodeById(id) to get the node.)
         */
        void BinaryTree::changeRoot(int newRootId)
    {
        // YOUR CODE GOES HERE
        Node *ptr = this->getNodeById(newRootId);
        
        if(ptr == nullptr) return;
        if(ptr == root) return;
        if (ptr->left != nullptr && ptr->right != nullptr) return;
        
        Node *parent = nullptr;
        std::queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *tmp = q.front();
            q.pop();

            if (tmp->left == ptr || tmp->right == ptr)
            {
                parent = tmp;
                break;
            }

            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }

        if (parent != nullptr)
        {
            if (parent->left == ptr)
                parent->left = nullptr;
            else
                parent->right = nullptr;
        }
        if (ptr->left == nullptr)
            ptr->left = root;
        else
            ptr->right = root;
        root = ptr;
        return;
    }
#endif


#ifdef USE_STUDENT_ADDNODE_IMPL
/**
 * Adds a new node with `value` as a child of `parent`.
 * New node's ID should be greatestIDEver + 1.
 * Don't forget to increment greatestIDEver.
 */
void BinaryTree::addNode(Node* parent, int value, bool isLeft) {
    // YOUR CODE GOES HERE
        if(parent == nullptr){
        if(root == nullptr){
            Node *newNode = new Node(++greatestIDEver, value);
            root = newNode;
            return;
        }
        else{
            return;
        }
    }
    if (isLeft){
        if(parent->left != nullptr){
            return;
        }
    }
    else{
        if(parent->right != nullptr){
            return;
        }
    }
    Node *newNode = new Node(++greatestIDEver, value);
    if(isLeft){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }
    return;
}
#endif


#ifdef USE_STUDENT_REMOVENODE_IMPL
/**
 * Removes the node with `id` from the tree.
 * Only works if the node has 0 or 1 child.
 * (Hint: You can call this->getNodeById(id) to get the node.)
 */
void BinaryTree::removeNode(int id) {
    // YOUR CODE GOES HERE
    Node *ptr = this->getNodeById(id);
    if(ptr == nullptr) return;
    if(ptr->left != nullptr && ptr->right != nullptr){
        return;
    }
    Node *child = (ptr->left != nullptr) ? ptr->left : ptr->right;
    if (ptr == root)
    {
        root = child;
        delete ptr;
        return;
    }
    Node *parent = nullptr;
    std::queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();

        if (tmp->left == ptr || tmp->right == ptr)
        {
            parent = tmp;
            break;
        }

        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
    if(parent != nullptr){
        if (parent->left == ptr)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        delete ptr;
    }
    

}
#endif


#ifdef USE_STUDENT_PRINTTREEINORDER_IMPL
/**
 * Prints the tree in In-Order (LNR)
 * Format: "Node value: [v], Node Id: [id]\n"
 * (Hint: Define a recursive helper function *inside* this #ifdef block)
 */
void BinaryTree::printTreeInOrder() {
    // YOUR CODE GOES HERE
    std::stack<Node *> s;
    Node *current = root;
    while (current != nullptr || !s.empty()){

        while (current != nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        std::cout << "Node value: " << current->value<< ", Node Id: " << current->id << std::endl;
        current = current->right;
    }
}
#endif