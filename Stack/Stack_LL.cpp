#include <iostream>
using namespace std;


template <typename T>
class Node{
public:
    T data;
    Node* next;
    Node(T value){
        this->data=value;
        this->next=nullptr;
    }
};

template <typename T>
class Stack{
private:
    Node<T>* top;
public:
    // CONSTRUCTOR
    Stack(){
        top=nullptr;
    } 

    // DESTRUCTOR
    ~Stack() {
        while (!isEmpty()) pop();
    }

    bool isEmpty(){
        return top==nullptr;
    }  

    // SIM TO INSERT AT HEAD
    void push(T value){
        Node<T>* newNode=new Node(value);
        newNode->next=top;
        top=newNode;
    }

    // SIM TO DELETE FROM HEAD
    void pop(){
        if (isEmpty()){
            cout<<"Stack is empty."<<endl;
            return;
        } 
        Node<T>* temp=top;
        top=top->next;
        delete temp;
    }

    // TOP/HEAD ELEMENT 
    T peek(){
        if (!isEmpty()){
            return top->data;
        } 
        cout<<"Stack is empty."<<endl;
        return T();
    }

    // TRAVERSAL
    void display(){
        Node<T>* current=top;
        while (current!=nullptr){
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<"\n";
    }
};

int main() {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack: ";
    stack.display();   
    cout << "Top element: " << stack.peek() << "\n";
    stack.pop();
    cout<<"Stack: ";
    stack.display();   

    return 0;
}
