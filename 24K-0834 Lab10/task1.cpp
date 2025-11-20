#include<iostream>
using namespace std;


class MinHeap {
    int heap[10];
    int size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    void heapifyUp(int index) {
        while (index != 0 && heap[parent(index)] >heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
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
};

int main() {
    MinHeap H;

    H.insert(1);
    H.insert(3);
    H.insert(4);
    H.insert(5);

    cout << "Heap before inserting new package: ";
    H.displayHeap();
    H.insert(2);
    cout << "Heap after inserting new package with priority 2: ";
    H.displayHeap();

    return 0;
}
