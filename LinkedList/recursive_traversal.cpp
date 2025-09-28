#include <iostream>
#include "linked_list.cpp"
using namespace std;
// PROTOTYPE
void printForward(Node* head);
void printBackward(Node* head);

// FORWARD PRINTING
void printForward(LinkedList &list) {
    cout << "Printing in Forward Direction: ";
    printForward(list.getHead()); 
}
void printForward(Node* head){
    if (head==nullptr) return;
    cout<<head->data<<" ";
    printForward(head->next);
}   

// BACKWARD PRINTING
void printBackward(LinkedList &list){
    cout<<"Printing in Backward Direction: ";
    printBackward(list.getHead());
}
void printBackward(Node* head){
    if (head==nullptr) return;
    printBackward(head->next);
    cout<<head->data<<" ";
}