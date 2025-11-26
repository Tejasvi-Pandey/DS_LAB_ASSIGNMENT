#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];  // heap array
    int size;

    PriorityQueue() {
        size = 0;
    }

    // Insert a value in heap
    void push(int val) {
        arr[size] = val;
        int i = size;
        size++;

        // Heapify UP
        while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Delete max element (root)
    int pop() {
        if (size == 0) return -1;

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapifyDown(0);
        return root;
    }

    void heapifyDown(int i) {
        int largest = i;
        int left  = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] > arr[largest])
            largest = left;

        if (right < size && arr[right] > arr[largest])
            largest = right;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

    bool empty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(30);

    cout << pq.top() << endl; // 30
    pq.pop();
    cout << pq.top() << endl; // 20

    return 0;
}
