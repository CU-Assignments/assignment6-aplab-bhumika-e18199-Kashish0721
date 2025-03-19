#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;          // Array to store the elements of the queue
    int front;         // Index of the front element
    int rear;          // Index of the rear element
    int capacity;      // Maximum capacity of the queue
    int currentSize;   // Current size of the queue

public:
    // Constructor to initialize the queue with a given capacity
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        currentSize = 0;
    }

    // Destructor to free the allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation: Adds an element at the rear of the queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << x << endl;
            return;
        }

        // Move the rear pointer to the next position in a circular manner
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        currentSize++;
        cout << x << " enqueued to queue" << endl;
    }

    // Dequeue operation: Removes an element from the front of the queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue" << endl;
            return -1;  // Return an invalid value to indicate empty queue
        }

        int dequeuedValue = arr[front];
        front = (front + 1) % capacity;  // Move the front pointer to the next element in a circular manner
        currentSize--;
        return dequeuedValue;
    }

    // Get the front element of the queue without removing it
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return currentSize == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return currentSize == capacity;
    }

    // Get the current size of the queue
    int size() {
        return currentSize;
    }
};

int main() {
    // Create a queue of capacity 5
    Queue q(5);

    q.enqueue(10);  // Enqueue 10
    q.enqueue(20);  // Enqueue 20
    q.enqueue(30);  // Enqueue 30
    q.enqueue(40);  // Enqueue 40
    q.enqueue(50);  // Enqueue 50

    cout << "Front element is: " << q.getFront() << endl;  // Should print 10

    cout << q.dequeue() << " dequeued from queue" << endl;  // Should print 10
    cout << q.dequeue() << " dequeued from queue" << endl;  // Should print 20

    cout << "Front element is: " << q.getFront() << endl;  // Should print 30

    q.enqueue(60);  // Enqueue 60

    cout << "Queue size is: " << q.size() << endl;  // Should print 4

    if (q.isEmpty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    if (q.isFull()) {
        cout << "Queue is full!" << endl;
    } else {
        cout << "Queue is not full!" << endl;
    }

    return 0;
}
