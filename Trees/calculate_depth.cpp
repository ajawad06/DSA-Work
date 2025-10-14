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

int height(Node* node){
    if (node==nullptr) return 0;
    return 1+max(height(node->left),height(node->right));
}