#include <iostream>
using namespace std;
// Creating a node
class Node { //1|next -> 2|next -> 3|NULL
public:
	int value;   //Ch7.2 page 22
	Node* next; 
};

int main() {
 Node* head;
 Node* one = NULL;      //variables one, two, and three are declared as pointers to Node objects
 Node* two =  NULL;     //means they can store memory addresses
 Node* three = NULL;
 
 // allocate 3 nodes in the heap , using new 
 one = new Node();
 two = new Node();               //when a Node object using new,members of that object (like value and next) do not have specific values yet
 three = new Node();            //new Node() is used to access memory that is dynamically allocated 
 
 // Assign value values
 one->value = 1;               //that's why we assign value to 'value' and 'next'
 two->value = 2;               //as example, int 2 is assign to 'value'. why int 2? 
 three->value = 3;             //we already declared above that int value, that's why 'value' is assign to type: integer
 
 // Connect nodes
 one->next = two;              //we don't assign value here, but instead memory address of next Node member
 two->next = three;             
 three->next= NULL;            //safeguard here, as no other Node member is assign after 'three'
 
 // print the linked list value
 head = one;                  //set list to 'one'
 
 while (head != NULL) {
 cout << head->value;
 head = head->next;
 
 }
 
}

//-> is used to point to an element in class
//. is used to access data in a class


