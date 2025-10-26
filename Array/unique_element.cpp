// LEETCODE QUESTION: SINGLE NUMBER
#include <iostream>
using namespace std;
int unique_element(int arr[],int size){
    int unique=0;
    for (int i=0;i<size;i++){
        unique^=arr[i];
    }
    return unique;
}


