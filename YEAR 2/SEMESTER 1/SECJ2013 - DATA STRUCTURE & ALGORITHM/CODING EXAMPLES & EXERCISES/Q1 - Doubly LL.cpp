#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int ID;
    string Name;
    float Marks;

    Student(int id = 0, string name = "", float marks = 0.0) {
        ID = id;
        Name = name;
        Marks = marks;
    }
};

class Node {
public:
    Student student;
    Node* next;
    Node* prev;

    Node(Student s) : student(s), next(NULL), prev(NULL) {}
};

class DoublyLL {
private:
    Node* head;
    Node* tail; // Add tail for better handling of deleteLast

public:
    DoublyLL() : head(NULL), tail(NULL) {}

    void display();
    void insertAtFront(Student student);
    void insertMiddle(Student student, int position);
    void deleteLast();
    void calculateAverageAndCount();
};

void DoublyLL::display() {
    Node* current = head;
    while (current != NULL) {
        cout << "ID: " << current->student.ID 
             << ", Name: " << current->student.Name 
             << ", Marks: " << current->student.Marks << endl;
        current = current->next;
    }
    cout << endl;
}

void DoublyLL::insertAtFront(Student student) {
    Node* newNode = new Node(student);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLL::insertMiddle(Student student, int position) {
    if (position < 1) {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    Node* newNode = new Node(student);
    if (position == 1) {
        insertAtFront(student);
        return;
    }

    Node* currNode = head;
    for (int i = 1; i < position - 1 && currNode != NULL; ++i) {
        currNode = currNode->next;
    }

    if (!currNode) {
        cout << "Invalid position for insertion." << endl;
        delete newNode;
        return;
    }

    newNode->next = currNode->next;
    newNode->prev = currNode;
    if (currNode->next) {
        currNode->next->prev = newNode;
    } else {
        tail = newNode; // Update tail if new node is the last one
    }
    currNode->next = newNode;
}

void DoublyLL::deleteLast() {
    if (!tail) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = tail;
    if (tail->prev) {
        tail = tail->prev;
        tail->next = NULL;
    } else {
        head = tail = NULL;
    }
    delete temp;
}

void DoublyLL::calculateAverageAndCount() {
    if (!head) {
        cout << "No students in the list." << endl;
        return;
    }

    int count = 0;
    float totalMarks = 0;
    Node* current = head;

    while (current) {
        totalMarks += current->student.Marks;
        count++;
        current = current->next;
    }

    cout << "Average Marks: " << totalMarks / count << endl;
    cout << "Total Number of Students: " << count << endl;
}

int main() {
    DoublyLL list;

    Student s1(1, "Samad", 85.5);
    Student s2(2, "Baba", 90.0);
    Student s3(3, "Harlina", 78.0);

    list.insertAtFront(s3);
    list.insertAtFront(s2);
    list.insertAtFront(s1);

    cout << "Initial list of students:" << endl;
    list.display();

    cout << "\nInserting a student in the middle:" << endl;
    Student s4(4, "Diana", 88.0);
    list.insertMiddle(s4, 2); // Insert at position 2
    list.display();

    cout << "\nDeleting the last student:" << endl;
    list.deleteLast();
    list.display();

    cout << "\nCalculating average marks and total number of students:" << endl;
    list.calculateAverageAndCount();

    return 0;
}

