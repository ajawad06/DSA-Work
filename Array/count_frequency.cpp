#include <iostream>
using namespace std;
int count_frequency(int arr[],int size,int key){
    int count=0;
    for (int i=0;i<size;i++){
        if (arr[i]==key){
            count++;
        }
    }
    return count;
}

