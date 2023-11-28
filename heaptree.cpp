#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Min Heap
class MinHeap {
private:
    int heap[MAX_SIZE];
    int heapSize;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heapSize && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }

        if (rightChild < heapSize && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap() : heapSize(0) {}

    void insert(int value) {
        heap[heapSize] = value;
        heapifyUp(heapSize);
        heapSize++;
    }

    int extractMin() {
        if (heapSize == 0) {
            cout << "Heap is empty";
        }

        int minValue = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapifyDown(0);

        return minValue;
    }

    int size() const {
        return heapSize;
    }

    void displayTree() const {
        for (int i = 0; i < heapSize; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

// Max Heap
class MaxHeap {
private:
    int heap[MAX_SIZE];
    int heapSize;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heapSize && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heapSize && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    MaxHeap() : heapSize(0) {}

    void insert(int value) {
        heap[heapSize] = value;
        heapifyUp(heapSize);
        heapSize++;
    }

    int extractMax() {
        if (heapSize == 0) {
            throw out_of_range("Heap is empty");
        }

        int maxValue = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapifyDown(0);

        return maxValue;
    }

    int size() const {
        return heapSize;
    }

    void displayTree() const {
        for (int i = 0; i < heapSize; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

// Manual sorting function for ascending order
void manualSortAscending(int arr[], int size) {
    int n = size;

    for (int i = n / 2 - 1; i >= 0; i--) {
        swap(arr[i], arr[n - 1 - i]);
    }
}

// Manual sorting function for descending order
void manualSortDescending(int arr[], int size) {
    int n = size;

    for (int i = 0; i < n / 2; i++) {
        swap(arr[i], arr[n - 1 - i]);
    }
}

int main() {
    // Example usage:
    MinHeap minHeap;
    MaxHeap maxHeap;

    // Insert elements into the heaps
    minHeap.insert(4);
    minHeap.insert(2);
    minHeap.insert(8);
    minHeap.insert(5);
    minHeap.insert(1);

    maxHeap.insert(4);
    maxHeap.insert(2);
    maxHeap.insert(8);
    maxHeap.insert(5);
    maxHeap.insert(1);

    cout << "Min Heap Tree: ";
    minHeap.displayTree();
    cout << endl;

    cout << "Max Heap Tree: ";
    maxHeap.displayTree();
    cout << endl;

    // Sort elements in ascending order manually
    int ascendingOrder[MAX_SIZE];
    int ascendingSize = 0;

    while (minHeap.size() > 0) {
        ascendingOrder[ascendingSize++] = minHeap.extractMin();
    }

    manualSortAscending(ascendingOrder, ascendingSize);

    cout << "Ascending Order: ";
    for (int i = 0; i < ascendingSize; i++) {
        cout << ascendingOrder[i] << " ";
    }
    cout << endl;
    cout << endl;
    // Sort elements in descending order manually
    int descendingOrder[MAX_SIZE];
    int descendingSize = 0;

    while (maxHeap.size() > 0) {
        descendingOrder[descendingSize++] = maxHeap.extractMax();
    }

    manualSortDescending(descendingOrder, descendingSize);

    cout << "Descending Order: ";
    for (int i = 0; i < descendingSize; i++) {
        cout << descendingOrder[i] << " ";
    }
    cout << endl;
    cout << endl;
    return 0;
}