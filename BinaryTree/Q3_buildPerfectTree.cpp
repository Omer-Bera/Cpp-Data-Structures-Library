#include "BinaryTree.h"
#include <cmath>
#include <stack>
#include <queue>


// Q3
/*Node* findParent(Node* ptr){
    std::queue<Node*>q;
    Node * parent = nullptr;

    q.push(root);
    while(!q.empty()){
        Node * tmp = q.front();
        q.pop();
        if(tmp->left == ptr || tmp->right == ptr){
            parent = tmp;
            break;
        }
        if(tmp->left != nullptr) q.push(tmp->left);
        if(tmp->right != nullptr) q.push(tmp->right);
    }
    return parent;
}*/

void BinaryTree::buildPerfectTree(int* values, int size) {
    // TODO: Implement Q3
    std::stack<Node*>s;
    BinaryTree t;
    t.root = new Node(0, values[0]);
    t.greatestIDEver = 0;
    s.push(root);
    Node * tmp;
    bool isLeft = true;
    addNode(root, values[i], isLeft);
    int i = 1;
    while(i<size){
        
        s.push(new Node(i, values[0]))
        i++;
    }
    for(int i = 1; i < size; i++){
        tmp = s.top();
        s.pop();
        addNode(tmp, values[i], bool isLeft);
        isLeft = !(isLeft);
    }
    

}