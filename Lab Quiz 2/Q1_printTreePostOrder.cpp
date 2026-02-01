
#include "BinaryTree.h"

#ifdef USE_STUDENT_Q1_IMPL

// Q1: Post-Order
void BinaryTree::helperPost(Node* ptr){
        if(ptr == nullptr) return;
        if(ptr->left != nullptr) helperPost(ptr->left);
        if(ptr->right != nullptr) helperPost(ptr->right);
        std::cout<<"Node value: "<<ptr->value<<", Node Id: "<<ptr->id<<std::endl;

        return;
}
void BinaryTree::printTreePostOrder() {
    // TODO: Implement Q1
    helperPost(root);
}

#endif
