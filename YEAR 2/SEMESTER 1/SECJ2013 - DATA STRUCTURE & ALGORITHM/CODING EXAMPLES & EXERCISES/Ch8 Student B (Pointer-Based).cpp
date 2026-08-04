#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    void push(char ch) {
        Node* newNode = new Node();
        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return '\0';
        }
        char poppedData = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedData;
    }

    char stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return '\0';
        }
        return top->data;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    char elements[] = {'A', 'B', 'C', 'D', 'E'};
        for (int i = 0; i < 5; i++) {
        stack.push(elements[i]);
    }

    stack.pop();
    stack.pop();

    cout << "Top element: " << stack.stackTop() << endl;

    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    cout << "Remaining stack elements: ";
    stack.display();

    return 0;
}

