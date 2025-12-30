#include <iostream>
#include <vector>
using namespace std;

class MaxHeap{
private:
    vector<int> heap;

    void heapifyUp(int index){
        if (index&& heap[index]>heap[(index-1)/2]){
            swap(heap[index],heap[(index-1)/2]);
            heapifyUp((index-1)/2);
        }
    }

    void heapifyDown(int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;

        if (left<heap.size()&& heap[left]>heap[largest]){
            largest=left;
        }
        if (right<heap.size()&& heap[right]>heap[largest]){
            largest=right;
        }
        if (largest!=index){
            swap(heap[index],heap[largest]);
            heapifyDown(largest);
        }
    }
public:
    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size()-1);
    }

    void removeMax(){
        if (heap.empty()){
            cout<<"Heap is empty\n";
            return;
        }
        heap[0]=heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap(){
        for (int i: heap){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(3);
    h.insert(1);
    h.insert(6);
    h.insert(5);
    h.insert(2);

    h.printHeap(); // 6 5 3 1 2

    h.removeMax();
    h.printHeap(); // 5 2 3 1

}