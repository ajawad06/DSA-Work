#include <iostream>
using namespace std;
int remove_duplicates(int arr[],int size){
    int j=0;
    for (int i=1;i<size;i++){
        if (arr[i]!=arr[j]){ // if unique element found
            j++;             // increase the count of unique 
            arr[j]=arr[i];   // move it next to last unique
        }
    }
    return j+1; // new size
}


