#include <iostream>
using namespace std;

class Node {
	public:
	int value;
	Node* next; 
 };
 
 
class LinkedList {
public:
	Node* head;
	Node* tail;
	
	LinkedList() {     // Constructor to initialize head and tail
		head = NULL;
		tail = NULL;
	}
 
 void insertAtBeginning(int value) { // Function to Insert a new node at the beginning of the list
 	Node* newNode = new Node;
 	newNode->value = value;
 	
 	if (head == NULL) { // If the list is empty, the new node becomes the head
	 head = newNode;
 } else {
 	newNode->next = head;
 	head = newNode;
 }
 
 void insertAtEnd(int value) { // Function Insert a new node at the end of the list
 	Node* newNode = new Node(value);
 	
 	if (head == NULL) {
 		head = newNode;
 		tail = newNode;
	 } else {
	 	tail->next = newNode;
	 	tail = newNode;
	 }	
 }
 
 // Function to Insert a new node at a specific position in the list
 void insertAtPosition(int value, int position) {
 }
 
 // Function to Delete the first node of the list
 void deleteFromBeginning() {
 }
 
 // Function to Delete the last node of the list
 void deleteFromEnd() {
 }
 
 // Function to find the key node in the list
 bool find(int key) {
 }
 
 // Function to Delete a node at a specific position in the list
 void deleteFromPosition(int position) {
 }
 
 // Function to print the nodes of the linked list
 void display() {
 }
 
}; //TheList


int main() {
 // Initialize a new linked list
 LinkedList list1;
 // Insert elements at the end
 list1.insertAtEnd(10);
 list1.insertAtEnd(20);
 // Insert element at the beginning
 list1.insertAtBeginning(5);
 // Insert element at a specific position
 list1.insertAtPosition(15, 3);
 
 cout << "Linked list after insertions: ";
 list1.display();
 
 bool f = list1.find(30);
 if (f==true )
 cout<<" Found "<<endl;
 else
 cout<<" Not Found "<<endl;
 
 // Delete element from the beginning
 list1.deleteFromBeginning();
 cout << "Linked list after deleting from beginning: ";
 list1.display();
 // Delete element from the end
 list1.deleteFromEnd();
 cout << "Linked list after deleting from end: ";
 list1.display();
 // Delete element from a specific position
 list1.deleteFromPosition(2);
 cout << "Linked list after deleting from position 2: ";
 list1.display();
 return 0;
}
