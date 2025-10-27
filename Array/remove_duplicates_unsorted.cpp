#include <iostream>
#include <set>
using namespace std;
int remove_duplicates(int arr[],int size){
    set<int> unique_elements;
    for (int i=0;i<size;i++){
        unique_elements.insert(arr[i]); // duplicates auto remove bc of set property
    }
    int index=0;
    for (int num:unique_elements){
        arr[index++]=num; // copy unique elements back
    }
    return index; //new size
}


