#include <iostream>
using namespace std;

int main(){
    // insert 20 in array 
    int array[10]={10,20,25,30,40,50};
    int size=6;
    int pos=2;
    // we shift elements from pos 3 to 5 towards left
    for (int i=pos;i<size-1;i++){
        array[i]=array[i+1];
    }
    size--;
    // display
    for (int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}