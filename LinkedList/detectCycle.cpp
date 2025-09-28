#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

bool hasCycle(Node* head){
    if (head==nullptr) return nullptr;

    Node* slow=head;
    Node* fast=head;
    while (fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;

        if (slow==fast){
            return true; // CYCLE FOUND
        }
    }
    return false; // CYCLE NOT FOUND
}