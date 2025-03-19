#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1, stack2;

public:
    // Enqueue operation: Push element to stack1
    void enqueue(int x) {
        stack1.push(x);
    }

    // Dequeue operation: Pop element from stack2
    int dequeue() {
        // If both stacks are empty, queue is empty
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return an invalid value to indicate empty queue
        }

        // If stack2 is empty, move elements from stack1 to stack2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // Pop the top element from stack2 (dequeue)
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    // Get the front element of the queue
    int front() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Return an invalid value to indicate empty queue
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return stack2.top();
    }
};

int main() {
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Dequeued element: " << q.dequeue() << endl; // Should print 10
    cout << "Dequeued element: " << q.dequeue() << endl; // Should print 20

    cout << "Front element: " << q.front() << endl; // Should print 30

    q.enqueue(50);

    cout << "Dequeued element: " << q.dequeue() << endl; // Should print 30
    cout << "Dequeued element: " << q.dequeue() << endl; // Should print 40
    cout << "Dequeued element: " << q.dequeue() << endl; // Should print 50

    // Queue is now empty
    if (q.isEmpty()) {
        cout << "Queue is empty!" << endl;
    }

    return 0;
}
