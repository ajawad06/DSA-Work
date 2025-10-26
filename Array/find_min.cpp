#include <iostream>
using namespace std;
int find_min(int arr[],int size){
    int minimum=arr[0];
    for (int i=1;i<size;i++){
        if (minimum>arr[i]){
            minimum=arr[i];
        }
    }
    return minimum;
}
