#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* reverseList(Node* head){
    if (head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newHead=reverseList(head->next);
    head->next->next=head;
    head->next=nullptr;

    return newHead;
}