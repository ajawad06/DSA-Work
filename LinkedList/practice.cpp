#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=nullptr;
    }
};
class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head=nullptr;
    }
    void insertAtHead(int val){
        Node* node=new Node(val);
        node->next=head;
        head=node;
    }
    
    void deleteFromHead(){
        if (head==nullptr) return;
        Node* temp=head;
        head=head->next;
        delete temp;
    }

    void print(){
        Node* temp=head;
        while (temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    Node* findLastNode(){
        if (head==nullptr) return nullptr;
        Node* temp=head;
        while (temp->next!=nullptr){
            temp=temp->next;
        }
        return temp;
    }
    void insertAtEnd(int val){
        Node* node=new Node(val);
        if (head==nullptr){
            head=node;
            return;
        }
        Node* temp=findLastNode();
        temp->next=node;
    }
    void deleteAtEnd(){
        if (head==nullptr) return;
        if (head->next==nullptr){
            delete head; 
            head=nullptr;   
        } 

        Node* temp=head;
        while (temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }

    Node* getNode(int pos){
        if (head==nullptr) return nullptr;
        if (pos<1) return nullptr;
        Node* temp=head;
        int count=1;
        while (temp!=nullptr){
            if (count==pos){
                return temp;
            }
            temp=temp->next;    
            count++;
        }
        return nullptr;
    }
    void insertAtPos(int val, int pos){
        if (pos<1) return;
        if (pos==1) {
            insertAtHead(val);
            return;
        }
        Node* prev=getNode(pos-1);
        if (prev==nullptr) return;
        Node* node=new Node(val);
        node->next=prev->next;
        prev->next=node;
        
    }
    void deleteAtPos(int pos){
        if (head==nullptr) return;
        if (pos<1) return;
        if (pos==1) {
            deleteFromHead();
            return;
        }
        Node* prev=getNode(pos-1);
        if (prev==nullptr) return;
        Node* deleteNode=prev->next;
        prev->next=deleteNode->next;
        delete deleteNode;
    }

    void printfrwrd(Node* head){
        if (head==nullptr) return;
        cout<<head->data;
        printfrwrd(head->next);
    }
    void printrvrse(Node* head){
        if (head==nullptr) return;
        printrvrse(head->next);
        cout<<head->data;
    }

    /*  
QUESTION: Write a C++ function that takes a linked list and two integers X and Y as input.
Function will modify the linked list such that it keeps X number of nodes then deletes next Y number of nodes.
This process will continue until end of the linked list. Your code should cater for any boundary conditions.

Input:
X = 2, Y = 3
Linked List: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11

Output:
Linked List: 1 -> 2 -> 6 -> 7 -> 11  
*/

};
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void modifyList(Node* head,int x,int y){
    Node* curr=head;
    Node* temp;
    while (curr!=nullptr){
        //skip x no.of nodes
        for (int i=1;curr!=nullptr && i<x;i++){
            curr=curr->next;
        }
        if (curr==nullptr) return;
        temp=curr->next;

        for (int i=0;i<y && temp!=nullptr;i++){
            Node* del=temp;
            temp=temp->next;
            delete del;
        }

        curr->next=temp;
        curr=temp;
    }
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

