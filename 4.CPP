#include <iostream>
using namespace std;

// Node structure to represent each element in the stack
struct Node {
    int data;       // Data of the node
    Node* next;     // Pointer to the next node
};

class Stack {
private:
    Node* top;      // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack() {
        top = nullptr;
    }

    // Destructor to free the allocated memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push operation: Adds an element to the top of the stack
    void push(int x) {
        Node* newNode = new Node;  // Create a new node
        newNode->data = x;         // Assign the data to the new node
        newNode->next = top;       // Make the new node point to the current top
        top = newNode;             // Update top to the new node
        cout << x << " pushed to stack" << endl;
    }

    // Pop operation: Removes the element from the top of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;  // Return an invalid value to indicate underflow
        }

        Node* temp = top;        // Store the current top node
        int poppedValue = top->data;
        top = top->next;         // Move the top pointer to the next node
        delete temp;             // Delete the old top node
        return poppedValue;
    }

    // Peek operation: Returns the element at the top of the stack without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // Return an invalid value to indicate empty stack
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;

    // Testing stack operations
    s.push(10);  // Push 10
    s.push(20);  // Push 20
    s.push(30);  // Push 30
    s.push(40);  // Push 40

    cout << "Top element is: " << s.peek() << endl;  // Should print 40

    cout << s.pop() << " popped from stack" << endl;  // Should print 40
    cout << s.pop() << " popped from stack" << endl;  // Should print 30

    cout << "Top element is: " << s.peek() << endl;  // Should print 20

    s.push(50);  // Push 50

    cout << "Top element is: " << s.peek() << endl;  // Should print 50

    while (!s.isEmpty()) {
        cout << s.pop() << " popped from stack" << endl;  // Pop all elements
    }

    // Stack should now be empty
    if (s.isEmpty()) {
        cout << "Stack is empty!" << endl;
    }

    return 0;
}
