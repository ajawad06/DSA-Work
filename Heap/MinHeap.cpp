#include <iostream>
#include <vector>
using namespace std;

class MinHeap{
private:
    vector<int> heap;

    void heapifyUp(int index){
        if (index&& heap[index]<heap[(index-1)/2]){
            swap(heap[index],heap[(index-1)/2]);
            heapifyUp((index-1)/2);
        }
    }

    void heapifyDown(int index){
        int smallest=index;
        int left=2*index+1;
        int right=2*index+2;

        if (left<heap.size()&& heap[left]<heap[smallest]){
            smallest=left;
        }
        if (right<heap.size()&& heap[right]<heap[smallest]){
            smallest=right;
        }
        if (smallest!=index){
            swap(heap[index],heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size()-1);
    }

    void removeMin(){
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
    MinHeap h;
    h.insert(3);
    h.insert(1);
    h.insert(6);
    h.insert(5);
    h.insert(2);

    h.printHeap(); // 1 2 6 5 3

    h.removeMin();
    h.printHeap(); // 2 3 6 5
}