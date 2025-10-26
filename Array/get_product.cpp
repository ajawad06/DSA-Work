#include <iostream>
using namespace std;
int product(int arr[],int size){
    int product=1;
    for (int i=0;i<size;i++){
        product*=arr[i];
    }
    return product;
}