#include <iostream>
using namespace std;

int main(){
    // insert 25 in array at position/index 2
    int array[10]={10,20,30,40,50};
    int size=5;
    int pos=2;
    int value=25;
    // we shift elements from pos 2 to 5 towards right
    for (int i=size;i>pos;i--){
        array[i]=array[i-1];
    }
    // insert + size increment
    array[pos]=value;
    size++;
    // display
    for (int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }

}