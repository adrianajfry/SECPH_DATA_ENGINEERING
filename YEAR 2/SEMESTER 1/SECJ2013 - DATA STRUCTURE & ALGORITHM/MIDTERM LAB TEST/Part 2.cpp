#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

class Website {
public:
    string name;
    string ip;

    Website(string n = "", string i = "") : name(n), ip(i) {}
};

class Stack {
private:
    int top;
    Website data[MAX_SIZE];  // Array of Website objects

public:
    void createStack() {
        top = -1;
    }

    void push(const Website& newWebsite) {
        if (isFull()) {
            cout << "Sorry, Cannot push item. Stack is now full!" << endl;
        } else {
            top++;
            data[top] = newWebsite;
        }
    }

    Website pop() {
        if (isEmpty()) {
            cout << "Sorry, Cannot pop item. Stack is empty!" << endl;
            return Website();
        } else {
            Website item = data[top];
            top--;
            return item;
        }
    }

    Website stackTop() {
        if (isEmpty()) {
            cout << "Sorry, stack is empty!" << endl;
            return Website();
        } else {
            return data[top];
        }
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void display() {
        if (isEmpty()) {
            cout << "(empty stack)" << endl;
        } else {
            cout << "Stack contents (top to bottom):" << endl;
            for (int i = top; i >= 0; i--) {
                cout << "Website: " << data[i].name << ", IP: " << data[i].ip << endl;
            }
        }
    }
};

int main() {
    Stack websiteStack;
    websiteStack.createStack();

    int choice;
    string name, ip;

    do {
        cout << "\nMenu:\n";
        cout << "1. Push Website\n";
        cout << "2. Pop Website\n";
        cout << "3. Display Stack\n";
        cout << "4. Show Top Website\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Website name: ";
                cin.ignore();  // Ignore any leftover newline character
                getline(cin, name);
                cout << "Enter Website IP: ";
                getline(cin, ip);
                websiteStack.push(Website(name, ip));
                break;

            case 2: {
                Website popped = websiteStack.pop();
                if (!popped.name.empty() || !popped.ip.empty()) {
                    cout << "Popped: " << popped.name << " (" << popped.ip << ")" << endl;
                }
                break;
            }

            case 3:
                websiteStack.display();
                break;

            case 4: {
                Website topWebsite = websiteStack.stackTop();
                if (!topWebsite.name.empty() || !topWebsite.ip.empty()) {
                    cout << "Top Website: " << topWebsite.name << " (" << topWebsite.ip << ")" << endl;
                }
                break;
            }

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1-5.\n";
        }
    } while (choice != 5);

    return 0;
}

