/*  
QUESTION: Write a C++ function that takes a linked list and two integers X and Y as input.
Function will modify the linked list such that it keeps X number of nodes then deletes next Y number of nodes.
This process will continue until end of the linked list. Your code should cater for any boundary conditions.

Input:
X = 2, Y = 3
Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11

Output:
Linked List: 1 -> 2 -> 6 -> 7 -> 1   
*/

//  ======== SOLUTION ========
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void modifyList(Node* head,int x,int y){
    Node* curr=head;
    Node* temp;
    while (curr){
        // skip x nodes
        for (int i=1; curr!=nullptr&&i<x;i++){
            curr=curr->next;
        }
        if (curr==nullptr) return;

        // delete y nodes
        temp=curr->next;
        for (int i=0;temp!=nullptr && i<y;i++){
            Node* del=temp;
            temp=temp->next;
            delete del;
        }
        curr->next=temp;
        curr=temp;
    }
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    // Creating linked list: 1->2->3->4->5->6->7->8->9->10
    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= 11; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    int x,y;
    cout<<"Enter X:";
    cin>>x;
    cout<<"Enter Y:";
    cin>>y;
    cout << "\nOriginal List: ";
    printList(head);
    modifyList(head,x,y);
    cout << "\nModified List (Keep " << x<< ", Delete " << y << "): ";
    printList(head);
    return 0;
}
