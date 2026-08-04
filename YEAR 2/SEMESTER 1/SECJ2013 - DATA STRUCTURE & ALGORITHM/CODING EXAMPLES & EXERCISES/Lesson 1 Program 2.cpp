#include <iostream>
using namespace std;

class Node {
public:
	char data;
	Node* next;
	Node(char data) {
		this->data = data;
		this->next = NULL;
	}
};

class TheList {
private:
	Node* head;

public:
 TheList() { 
 head = NULL;
 }
 
 void insert(char data) {      // Ch7.2 page 30
 	Node* newNode = new Node(data);
 	newNode->next = head;
 	head = newNode;
 }
 
 void display() {     
 Node* current = head;                   // Ch7.2 page 42
 	while (current != NULL) {
 		cout << current->data << "->" ;
 		current = current->next;
	 }
	 cout << "NULL" << endl;
 }
};

int main() {
 TheList myList;
 myList.insert('Z'); 
 myList.insert('T');
 myList.insert('A');
 cout << "The Link List - Singly: "; 
 //A|next -> T|next -> Z|NULL
 myList.display();
 return 0;
}

// MCQ 
// What will be the output of the following code snippet for 10->11->12->13->14? 
/* 
void solve (ListNode* head) {
 while(head != NULL) {
cout << head -> data << " ";
head = head -> next;
}
}
A. 10 11 12 13 14
B. 11 12 13 14 
C. 14 13 12 11 10
D. 13 12 11 10 */

