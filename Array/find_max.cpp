#include <iostream>
using namespace std;
int find_max(int arr[],int size){
    int maximum=arr[0];
    for (int i=1;i<size;i++){
        if (maximum<arr[i]){
            maximum=arr[i];
        }
    }
    return maximum;
}

