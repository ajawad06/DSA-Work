#include <iostream>
using namespace std;
template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T value){
        data=value;
        next=nullptr;
    }
};

template <typename T>
class CircularLinkedList{
private:
    Node<T>* tail;
public: 
    // CONSTRUCTOR
    CircularLinkedList(){
        tail=nullptr;
    }

    // INSERT AT BEGINNING
    void insertAtFront(T value){
        Node<T>* newNode=new Node<T>(value);
        if (tail==nullptr){
            tail=newNode;
            newNode->next=newNode;
            return;
        }
        newNode->next=tail->next;
        tail->next=newNode;
    }

    // TRAVERSAL
    void printList(){
        if (tail==nullptr) {
            cout<<"List is empty"<<endl;
            return;
        }
        Node<T>* temp=tail->next; // tail->next is head basically
        do {
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=tail->next);
    }

    // HELPER FUNCTIONS
    
    // Gives Length
    int getLength(){
        if (tail==nullptr) return 0;
        int length=0;
        Node<T>* temp=tail->next;
        do {
            length++;
            temp=temp->next;
        }while(temp!=tail->next);
        return length;
    }

    // Get Node bc for right pointer we cannot go back cz no prev pointer so use this
    Node<T>* getNode(int pos){
        if (pos==0) return nullptr;
        if (pos==1) return tail;
        int count=0;
        Node<T>* temp=tail->next;
        do {    
            count++;
            if (pos==count) return temp;
            temp=temp->next;        
        } while (temp!=tail->next);

        return nullptr;
    }

    // PALINDROME FUNCTION
    bool isPalindrome(){
        Node<T>* left=tail->next;
        Node<T>* right=tail;
        int size=getLength();
        for (int i=0;i<size/2;i++){
            if (left->data!=right->data) return false;
            left=left->next;
            right=getNode(size-i-1);
        }
        return true;
    }
};

int main(){
    CircularLinkedList<int> list1;
    list1.insertAtFront(10);
    list1.insertAtFront(20);
    list1.insertAtFront(30);
    list1.insertAtFront(20);
    list1.insertAtFront(10);
    cout << "List 1: ";
    list1.printList();
    if (list1.isPalindrome()){
        cout<<" is a palindrome"<<endl;
    }else{
        cout<<" is not a palindrome"<<endl;
    }

    CircularLinkedList<string> list2;
    list2.insertAtFront("cat");
    list2.insertAtFront("dog");
    list2.insertAtFront("cat");
    cout <<"List 2: ";
    list2.printList();
    if (list2.isPalindrome()){
        cout<<" is a palindrome"<<endl;
    }else{
        cout<<" is not a palindrome"<<endl;
    }

    CircularLinkedList<char> list3;
    list3.insertAtFront('a');
    list3.insertAtFront('b');
    list3.insertAtFront('c');
    list3.insertAtFront('d');
    list3.insertAtFront('a');
    cout <<"List 3: ";
    list3.printList();
    if (list3.isPalindrome()){
        cout<<" is a palindrome"<<endl;
    }else{
        cout<<" is not a palindrome"<<endl;
    }

    return 0;
}