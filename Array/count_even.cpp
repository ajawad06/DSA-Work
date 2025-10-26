#include <iostream>
using namespace std;
int count_even(int arr[],int size){
    int count=0;
    for (int i=0;i<size;i++){
        if (arr[i]%2==0){
            count++;
        }
    }
    return count;
}

