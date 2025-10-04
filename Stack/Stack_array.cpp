#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    int top;          // index of top element
    int capacity;     // total capacity
    T* arr;           // dynamic array

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // PUSH operation
    void push(T value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    // POP operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
            return;
        }
        top--;
    }

    // PEEK operation
    T peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return T();
        }
        return arr[top];
    }

    // DISPLAY stack elements (top to bottom)
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack<int> stack(5);  // stack with capacity 5

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    stack.display();
    return 0;
}
