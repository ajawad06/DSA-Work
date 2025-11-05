#include <iostream>
using namespace std;

class Queue{
private:
    int front,rear,size,capacity;
    int* arr;
public:
    Queue(int cap){
        capacity=cap;
        arr=new int[capacity];
        size=0;
        front=-1;
        rear=-1;
    }
    
    void enqueue(int x){
        if (size==capacity){
            cout<<"Queue is full."<<endl;
            return;
        }
        // First element case
        if (front == -1) front = 0;
        rear=(rear+1)%capacity;
        arr[rear]=x;
        size++;
    }
    
    void dequeue(){
        if (size==0){
            cout<<"Queue is empty."<<endl;
            return;
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front=(front+1)%capacity;
        }
        size--;
    }
    
    int getFront() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

};