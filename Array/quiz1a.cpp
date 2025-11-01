// QUESTION:
// You are making an array based list with following class declaration:
// class ArrayList{
// private: 
//     float*A;
//     int size;
//     int capacity;
// public:
//     ArrayList();
//     void insertAtEnd(float n);
//     void printRec(int num);
//     int getSize();
// }
// A) Write the constructor
// B) Write function insertAtEnd(float n)
// C) Write function printRec(int num) such that when i call list.printRec(list.getSize()) in main function, I pritn array from 1 to size.

#include <iostream>
using namespace std;

class ArrayList{
private: 
    float*A;
    int size;
    int capacity;
public:
    // PART A
    ArrayList(int capacity){
        this->capacity=capacity;
        A=new float[capacity];
        this->size=0;
    }
    // PART B
    void insertAtEnd(float n){
        if (size==capacity){
            capacity*=2;
            float* B=new float[capacity];
            // copy data from A to B
            for (int i=0;i<size;i++){
                B[i]=A[i];
            }
            delete [] A;
            A=B;
        }
        A[size]=n;
        size++;
    }
    // PART C
    void printRec(int num){
        if (num==0) return;
        printRec(num-1);
        cout<<A[num-1]<<" ";
    }

    int getSize(){
        return size;
    }
};
