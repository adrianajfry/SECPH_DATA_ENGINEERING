#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char name[100];
    Node* next;
    Node* prev;

    Node(const char* name) {
        strcpy(this->name, name);
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(const char* name);
    void countAndDisplay();
    void deleteLastNode();
    void insertAtSecond(const char* name);
    void displayList();
};

void DoublyLinkedList::insertAtEnd(const char* name) {
    Node* newNode = new Node(name);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::countAndDisplay() {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        count++;
        cout << "Node " << count << ": " << current->name << endl;
        current = current->next;
    }
    cout << "\nTotal Nodes: " << count << endl;
}

void DoublyLinkedList::deleteLastNode() {
    if (head == NULL) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
}

void DoublyLinkedList::insertAtSecond(const char* name) {
    Node* newNode = new Node(name);
    if (head == NULL) {
        cout << "Cannot insert at second position, list is empty." << endl;
        delete newNode;
        return;
    }
    if (head->next == NULL) {
        cout << "Cannot insert at second position, list has only one node." << endl;
        delete newNode;
        return;
    }
    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
}

void DoublyLinkedList::displayList() {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        cout << "Node " << count++ << ": " << current->name << endl;
        current = current->next;
    }
}

int main() {
    DoublyLinkedList list;

    list.insertAtEnd("Ali");
    list.insertAtEnd("Baba");
    list.insertAtEnd("Chan");
    list.insertAtEnd("Diana");
    list.insertAtEnd("Ely");

    cout << "Total Node:" << endl;
    list.countAndDisplay();

    list.deleteLastNode();
    cout << "\nList after deleting last node:" << endl; // Deletes "Ely"
    list.displayList();

    list.insertAtSecond("Alisa"); // Inserts "Alisa" at the second node
    cout << "\nList after inserting 'Alisa' at second position:" << endl;
    list.displayList();

    return 0;
}

