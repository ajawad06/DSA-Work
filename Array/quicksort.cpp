#include <iostream>
using namespace std;

int partition(int arr[],int low,int high,int &pivotIndex){
    int pivot=arr[high];
    int i=low-1;
    for (int j=low;j<high;j++){
        if (arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    pivotIndex=i+1;
    return pivotIndex;
}
void quicksort(int arr[],int low,int high){
    if (low<high){
        int pivotIndex;
        partition(arr,low,high,pivotIndex);
        quicksort(arr,low,pivotIndex-1);
        quicksort(arr,pivotIndex+1,high);       
    }
}