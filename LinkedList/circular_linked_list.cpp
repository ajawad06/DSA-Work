#include <iostream>
using namespace std;

// GENERIC NODE CLASS
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

// GENERIC CIRCULAR LIST CLASS
template <typename T>
class CircularLinkedList{
private:
    Node<T>* tail;
public: 

    // ============== BASICS ==============

    // CONSTRUCTOR
    CircularLinkedList(){
        tail=nullptr;
    }

    // DESTRUCTOR
    ~CircularLinkedList(){
        if (!tail) return;
        Node<T>* current=tail->next;
        Node<T>* nextNode;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != tail->next);

        tail = nullptr;
    }

    // =============== INSERTIONS ===============

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

    // INSERT AT ENDING
    void insertAtTail(T value){
        Node <T>* newNode=new Node<T>(value);
        if (tail==nullptr){
            tail=newNode;
            newNode->next=newNode;
            return;
        }
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }

    // ============== DELETIONS ==============

    // DELETE FROM END
    void deleteFromEnd(){
        if (tail==nullptr) return;
        Node <T>* current=tail->next;
        if (current==tail){
            delete tail;
            tail=nullptr;
            return;
        }
        while (current->next!=tail){
            current=current->next;
        }
        current->next=tail->next;
        delete tail;
        tail=current;
    }

    // DELETE FROM START
    void deleteFromHead(){
        if (tail==nullptr) return;
        Node <T>* head=tail->next;
        if (head==tail){
            delete head;
            tail=nullptr;
            return;
        }
        tail->next=head->next;
        delete head;
    }


    // ============== TRAVERSALS ==============

    // TRAVERSAL
    void displayForward(){
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

    // ============= ZIG ZAG ORDER ============

    // ZIGZAG ORDERING
    void zigzagReorder(){
        if (tail == nullptr || tail->next == tail) return;
        bool flag=true;
        // two pointers to keep check on the two consecutive nodes
        Node<T>* current=tail->next->next;
        Node<T>* previous=tail->next;

        while (current!=tail->next){
            // condition checks
            if (flag){
                if (!(previous->data < current->data)){
                    swap(previous->data,current->data);  
                }
            }else{
                if (!(previous->data > current->data)){
                    swap(previous->data,current->data);  
                }
            }
            // advance pointers
            previous = current;
            current = current->next;
            // toggle flag
            flag=!flag;
        }
    }
};

int main(){
    CircularLinkedList<int> list;
    list.insertAtFront(1);
    list.insertAtFront(2);
    list.insertAtFront(6);
    list.insertAtFront(8);
    list.insertAtFront(7);
    list.insertAtFront(3);
    list.insertAtFront(4);
    cout << "Original List: ";
    list.displayForward();
    list.zigzagReorder();
    cout<<"\nList after ZigZag Reordering: ";
    list.displayForward();

    return 0;
}