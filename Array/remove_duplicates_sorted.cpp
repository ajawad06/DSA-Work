#include <iostream>
using namespace std;
int remove_duplicates(int arr[],int size){
    int unique=0;
    for (int i=0;i<size;i++){
        unique^=arr[i];
    }
    return unique;
}


