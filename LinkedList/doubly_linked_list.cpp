#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value){
        data=value;
        next=nullptr;
        prev=nullptr;
    }
};
class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
// ================== BASICS ====================

    // CONSTRUCTOR
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // DESTRUCTOR

    // ================== INSERTION ==================== 

    // INSERT AT BEGINNING
    void insertAtHead(int value){
        Node* newNode=new Node(value);
        if (head==nullptr){
            tail=newNode;
            head=newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    // INSERT AT END
    void insertAtTail(int value){
        Node* newNode=new Node(value);
        if (head==nullptr){
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }

    // ==================== DELETION ======================

    // DELETE FROM HEAD
    void deleteFromHead(){
        if (head==nullptr) return;
        Node* temp=head;
        head=head->next;
        if (head!=nullptr) {
            head->prev=nullptr;
        }else{
            tail=nullptr;
        }
        delete temp;
    }

    // DELETE FROM TAIL
    void deleteFromTail(){
        if (tail==nullptr) return;
        Node* temp=tail;
        tail=tail->prev;
        if (tail!=nullptr){
            tail->next=nullptr;
        }else{
            head=nullptr
        }
        delete temp;
    }

    // ================ TRAVERSALS ===============
    
    // PRINT LIST
    void printList(){
        Node*temp=head;
        while (temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    // REVERSE PRINT LIST
    void printReverseList(){
        Node* temp=tail;
        while (temp){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }

}