#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;        // Pointer to the array that will hold the stack elements
    int capacity;    // Maximum capacity of the stack
    int top;         // Index of the top element in the stack

public:
    // Constructor to initialize stack with a given capacity
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;  // Stack is empty initially
    }

    // Destructor to free memory
    ~Stack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
        cout << x << " pushed to stack" << endl;
    }

    // Pop an element from the stack
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return -1;  // Return an invalid value to indicate underflow
        }
        int popped = arr[top--];
        return popped;
    }

    // Get the top element of the stack without removing it
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;  // Return an invalid value to indicate the stack is empty
        }
        return arr[top];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Get the current size of the stack
    int size() {
        return top + 1;
    }
};

int main() {
    // Create a stack of capacity 5
    Stack stack(5);

    stack.push(10);  // Push 10 to the stack
    stack.push(20);  // Push 20 to the stack
    stack.push(30);  // Push 30 to the stack
    stack.push(40);  // Push 40 to the stack
    stack.push(50);  // Push 50 to the stack

    cout << "Top element is: " << stack.peek() << endl;  // Should print 50

    cout << stack.pop() << " popped from stack" << endl;  // Should print 50
    cout << stack.pop() << " popped from stack" << endl;  // Should print 40

    cout << "Top element is: " << stack.peek() << endl;  // Should print 30

    cout << "Stack size is: " << stack.size() << endl;  // Should print 3

    if (stack.isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}
