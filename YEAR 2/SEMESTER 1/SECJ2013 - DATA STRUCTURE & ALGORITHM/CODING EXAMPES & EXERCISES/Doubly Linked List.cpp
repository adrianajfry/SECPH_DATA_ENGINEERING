//Doubly Linked List
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
	three->next = NULL;
	
	one->prev = NULL;
	two->prev = one;
	three->prev = two;
	
	head = one;
	tail = three;
	
	cout << "Forward List" << endl;
	Node* current = head;
	while (current != NULL) {
		cout << current->value;
		current = current->next;
	} cout << endl; 
 
	cout << "Previous List" << endl;
	current = tail;          //don't use Node* here, as we are reusing 'current' memory space here
	while (current != NULL) {
		cout << current->value;
		current = current->prev;
	} cout << endl;
	
	return 0;
}
