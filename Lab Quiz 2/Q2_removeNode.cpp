#include "BinaryTree.h"
#include <queue>

// Q2
void BinaryTree::removeNode(int id) {
    // TODO: Implement Q2
    if(root == nullptr) return;
    Node * curr = getNodeById(id);
    if(curr == nullptr) return;
    Node * child = nullptr;
    Node * parent = nullptr;
    
    if(curr == root){
        if(root->right == nullptr && root->left == nullptr){
            delete root;
            root = nullptr;
            return;
        }
        else if(root->left != nullptr && root->right != nullptr){
            return;
        }
        else if(root->left != nullptr){
            child = root->left;
            delete root;
            root = child;
            delete child;
            return;
        }
        else{
            child = root->right;
            delete root;
            root = child;
            delete child;
            return;
        }
        
    }

    //find parent
    std::queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node * tmp = q.front();
        q.pop();
        if(tmp->left == curr || tmp->right == curr){
            parent = tmp;
            break;
        }
        if(tmp->left != nullptr) q.push(tmp->left);
        if(tmp->right != nullptr) q.push(tmp->right);
    }
    if(parent == nullptr) return;

    if(curr->left == nullptr){
        if(curr->right == nullptr){
            delete curr;
            curr = nullptr;
            return;
        }
        else{
            child = curr->right;
            if(parent->right == curr){
                parent->right = child;
            }
            if(parent->left == curr){
                parent->left = child;
            }
            delete curr;
            curr = nullptr;
            return;
        }
    }
    else{
        if(curr->right != nullptr)
            return;
        else{
            child = curr->left;
            if(parent->right == curr){
                parent->right = child;
            }
            if(parent->left == curr){
                parent->left = child;
            }
            delete curr;
            curr = nullptr;
            return;
        }
    }
            
}
