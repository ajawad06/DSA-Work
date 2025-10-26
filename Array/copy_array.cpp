#include <iostream>
using namespace std;
int* copy(int arr[],int size){
    int* copied_array = new int[size];
    for (int i=0;i<size;i++){
        copied_array[i]=arr[i];
    }
    return copied_array;
}
