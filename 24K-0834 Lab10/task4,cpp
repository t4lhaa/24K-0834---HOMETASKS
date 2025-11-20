#include<iostream>
using namespace std;


class MinHeap {
    int heap[10];
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

        int leftChild(int i) {
        return 2 * i + 1;
     }
    int rightChild(int i) {
         return 2 * i + 2;
     }

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] >heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }
        void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < size && heap[left] < heap[smallest]){
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]){
            smallest = right;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(){
        size = 0;
    }

    void insert(int priority) {
        if (size == 10) {
            cout << "Heap is full!" << endl;
            return;
        }
        heap[size] = priority;
        heapifyUp(size);
        size++;
    }

    void displayHeap() {
        for (int i = 0; i < size; i++){
            cout << heap[i] << " ";
        }
        cout << endl;
    }

int remove() {
    if (size <= 0){
        return -1;
        } 
    int minord = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
     return minord;
}



};

int main() {
 MinHeap orders;

    orders.insert(100);
    orders.insert(50);
    orders.insert(75);
    orders.insert(60);

    cout << "Heap after initial orders: ";
    orders.displayHeap();

    orders.insert(55);
    cout << "Heap after inserting 55: ";
    orders.displayHeap();

    int executed = orders.remove();
    cout << "Executed order with price: " << executed << endl;
    cout << "Heap after execution: ";
    orders.displayHeap();

    return 0;
}
