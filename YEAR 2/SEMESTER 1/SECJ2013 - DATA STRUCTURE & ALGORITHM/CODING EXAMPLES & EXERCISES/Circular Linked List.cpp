//Circular Linked List
#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;
};

int main () {
    Node* head = NULL;
    Node* tail = NULL;
    Node* one = NULL;
    Node* two = NULL;
    Node* three = NULL;

    one = new Node();
    two = new Node();
    three = new Node();

    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;
    three->next = one;   //connect the tail's(3) next to the head(1)

    one->prev = NULL;   //this will remain NULL in a circular list
    two->prev = one;
    three->prev = two;  //connect the head's(1) prev to the tail(3)

    head = one;
    tail = three;

    cout << "Forward List" << endl;
    Node* current = head;
    do {                      //loop until current reaches head again
        cout << current->value;
        current = current->next;
    } while (current != head);
    cout << endl;

    cout << "Previous List" << endl;
    current = tail;
    do {                      //loop until current reaches tail again
        cout << current->value;
        current = current->prev;
    } while (current != tail);
    cout << endl;

    return 0;
}
