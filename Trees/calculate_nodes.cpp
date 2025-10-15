#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* right;
    Node* left;

    Node(int value){
        this->data=value;
        right=nullptr;
        left=nullptr;
    }
};

int countNodes(Node* node){
    if (node==nullptr) return 0;
    return 1+countNodes(node->left)+countNodes(node->right);
}

int countLeaves(Node* node){
    if (node==nullptr) return 0;
    if (node->left==nullptr && node->right==nullptr) return 1;
    return countLeaves(node->left)+countLeaves(node->right);
}

void printLeaves(Node* ptr){
    if (ptr==nullptr) return;
    if (ptr->left==nullptr && ptr->right==nullptr) {
        cout<<ptr->data<<" ";
        return;
    }
    printLeaves(ptr->left);
    printLeaves(ptr->right);
}

int countInternalNodes(Node* node){
    if (node==nullptr) return 0;
    if (node->left==nullptr && node->right==nullptr) return 0;
    return 1+countInternalNodes(node->left)+countInternalNodes(node->right);
}
