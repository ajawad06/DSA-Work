#include <iostream>
using namespace std;
int search(int arr[],int size,int key){
    for (int i=0;i<size;i++){
        if (arr[i]==key){
            return arr[i];
        }
    }
    return -1;
}

