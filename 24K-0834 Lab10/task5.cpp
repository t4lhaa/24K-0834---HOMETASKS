#include <iostream>
using namespace std;

#define MAX 100

class MaxHeap {
    int heap[MAX];
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
        while (index != 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < size && heap[left] > heap[largest]){
            largest = left;
        }
        if (right < size && heap[right] > heap[largest]){
            largest = right;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() {
         size = 0;
     }

    void insert(int rating) {
        if (size == MAX) return;
        heap[size] = rating;
        heapifyUp(size);
        size++;
    }

    int remove() {
        if (size <= 0){
             return -1;
        }
        int maxRating = heap[0];
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        return maxRating;
    }

    void displayHeap() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap queue;

    queue.insert(1500);
    queue.insert(1200);
    queue.insert(1800);
    queue.insert(1600);

    cout << "Heap after building current queue: ";
    queue.displayHeap();

    queue.insert(1700);
    cout << "Heap after inserting 1700: ";
    queue.displayHeap();
    int matched = queue.remove();
    cout << "Matched player with rating: " << matched << endl;
    cout << "Heap after matching: ";
    queue.displayHeap();

    return 0;
}
