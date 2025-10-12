#include <iostream>
using namespace std;

// GENERIC STACK CLASS
template <typename T>
class Stack{
private:
    int capacity;
    int size;
    T* arr;
public:
    // CONSTRUCTOR
    Stack(int capacity){
        this->capacity=capacity;
        size=0;
        arr=new T[capacity];
    }
    
    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    void push(T x){
        if (!isFull()){
            arr[size++]=x;
            return;
        }
        cout<<"Stack is already full."<<endl;
    }

    T pop(){
        if (!isEmpty()){
            return arr[--size];
        }
        cout<<"Stack is already empty."<<endl;
        return T();
    }

    T peek(){
        if (!isEmpty()){
            return arr[size-1];
        }
        cout<<"Stack is already empty."<<endl;
        return T();
    }

    void clear(){
        size=0;
    }
    
};

bool matchingBrackets(char open,char close){
    // check closure of each pair
    return (open=='[' && close==']') || (open=='(' && close==')') || (open=='{' && close=='}');
}

bool validExpression(string expression){
    Stack<char> s(30);
    for (char c:expression){
        if (c=='{' || c=='(' || c=='['){
            s.push(c);
        }else if (c=='}' || c==')' || c==']'){
            if (s.isEmpty()) return false;
            // we match the latest element i.e. opening bracket in stack to the current closing bracket 
            if (!matchingBrackets(s.pop(),c)) return false;
        }
    }
    // if stack empty, brackets are in pairs
    return s.isEmpty();
}

int main(){
    cout<<"1 + 2 * (3 / 4) : "<<(validExpression("1 + 2 * (3 / 4)")?"Valid":"Invalid")<<endl;
    cout<<"1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14 : "<<(validExpression("1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14")?"Valid":"Invalid")<<endl;
    cout<<"1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10)} - 11 + (12*8) / {13 +13}] + 14 : "<<(validExpression("1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10)} - 11 + (12*8) / {13 +13}] + 14")?"Valid":"Invalid")<<endl;
}
