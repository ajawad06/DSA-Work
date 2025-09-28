#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* getMiddleNode(Node* head){
    if (head==nullptr) return nullptr;

    Node* slow=head;
    Node* fast=head;
    while (fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}