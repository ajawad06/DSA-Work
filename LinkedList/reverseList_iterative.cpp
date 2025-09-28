#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head){
    Node* current=head;
    Node* prev=nullptr;
    Node* next=nullptr;

    while (current!=nullptr){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev; // becomes new head
}