#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=nullptr;
    }
};
class LinkedList{
private:
    Node* head;
public:
    // CONSTRUCTOR
    LinkedList() {
        head = nullptr;
    }
    
    // ACCESS LAST NODE
    Node* getLastNode(){
        if (head == nullptr) return nullptr; 
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        return temp;
    }

    // ACCESS ANY NODE AT A CERTAIN POSITION
    Node* getNode(int position) {
        if (head == nullptr) {
            cout << "The list is empty right now." << endl;
            return nullptr;
        }
        if (position < 1) {
            cout << "Invalid position!" << endl;
            return nullptr;
        }
        Node* temp = head;
        int count = 1; // start counting positions from 1
        while (temp != nullptr) {
            if (count == position) {
                return temp;
            }
            temp = temp->next;
            count++;
        }
        cout << "The node does not exist." << endl;
        return nullptr;
    }       

   // INSERT AT BEGINNING
    void insertAtHead(int value){
        Node* temp=new Node(value);
        temp->next=head;
        head=temp;
        cout<<"Node with value "<<value<<" inserted at Head"<<endl;
    }
    
    // INSERT AT END
    void insertAtEnd(int value){
        Node* newNode = new Node(value);
        if (head == nullptr) {   
            head = newNode;
            return;
        }
        Node* lastnode=getLastNode();
        lastnode->next = newNode;
    }

    // INSERT AT CERTAIN POSITION
    void insertAtLocation(int location,int value){
        if (location < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (location == 1) {
            insertAtHead(value);
            return;
        }

        Node* prevPtr=getNode(location-1);
        if (prevPtr == nullptr) {
            cout << "Cannot insert at position " << location << ". Node does not exist." << endl;
            return;
        }
        Node* temp=new Node(value);
        temp->next=prevPtr->next;
        prevPtr->next=temp;
        cout<<"Node with value "<<value<<" inserted at position "<<location<<endl;
    }

    // DELETE FROM BEGINNING
    void deleteFromHead(){
        if (head == nullptr) {
        cout << "Empty list, nothing to delete." << endl;   // ✅ added check for empty list
        return;
        }
        Node* temp=head;
        head=head->next;
        cout << "Last node with value "<<temp->data<<" deleted." << endl;
        delete temp;
    }

    // DELETE LAST NODE
    void deleteLastNode(){
        if (head==nullptr){
            cout<<"Empty list, nothing to delete."<<endl;
            return;
        }
        // If only one node
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Last node deleted. List is now empty." << endl;
            return;
        }
        // Traverse to the second-last node
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        // Delete last node
        int value=temp->next->data;
        cout << "Last node with value "<<value<<" deleted." << endl;        
        delete temp->next;
        temp->next = nullptr;
    }

    // DELETE A NODE AT CERTAIN POSITION
    void deleteNodeAtLocation(int position){
        if (head == nullptr) {
            cout << "Empty list, nothing to delete." << endl;
            return;
        }

        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (position==1){
            deleteFromHead();  
            return;
        }
        Node* prev=getNode(position-1);
        if (prev == nullptr || prev->next == nullptr) {
            cout << "Position " << position << " does not exist." << endl;
            return;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        cout << "Deleted node at position " << position << " with value " << temp->data << endl;
        delete temp;
    }

    
    // COUNT NO.OF NODES 
    int countList(){
        int count=0;
        Node* temp=head;
        if (head==nullptr){
            cout<<"The list is empty right now."<<endl;
            return 0;
        }
        while (temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
};

