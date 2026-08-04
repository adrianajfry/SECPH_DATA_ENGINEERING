#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    char arr[MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(char ch) {
         if (isFull()) {
            cout << "Stack overflow! Cannot push item. Stack is full!" << endl;
            return;
        }
         top = top + 1;
         arr[top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop item. Stack is empty!" << endl;
            return '\0';
        }
        char item = arr[top];
        cout << "Popped value : " << item << endl;
        top = top - 1;
        return item;
    }

    char stackTop() {
         if (isEmpty()) {
            cout << "Sorry, stack is empty!" << endl;
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX - 1;
    }


    void display() {
         if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
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
