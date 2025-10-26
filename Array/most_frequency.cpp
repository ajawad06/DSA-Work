#include <iostream>
using namespace std;
int highest_frequency_element(int arr[],int size){
    int max_freq=0;
    int element=arr[0];
    for (int i=0;i<size;i++){
        int count=0;
        for (int j=0;j<size;j++){
            if (arr[i]==arr[j]){
                count++;
            }
        }
        if (count>max_freq){
            max_freq=count;
            element=arr[i];
        }
    }
    return element;
}

