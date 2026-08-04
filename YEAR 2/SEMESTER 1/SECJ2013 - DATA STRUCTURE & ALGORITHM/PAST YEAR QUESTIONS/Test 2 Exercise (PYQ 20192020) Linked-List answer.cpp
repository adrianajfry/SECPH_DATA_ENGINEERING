////////////////////////////////////////////////////////////////////////////////
// School of Computing, Faculty of Engineering, UTM
// SCSJ2013- Data Structures and Algorithms
// Semester 1, 2019/2020
// Lab Test  - Question 1 Linked List (30 marks)
// Name - Nurul Adriana Binti Kamal Kefri
// Matric Number - A23CS0258
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std; 

//Represents node of the linked list 
class Node { 
      public:
	      int num1; 
          int num2; 
	      Node* next; 
	      
	      Node(int a, int b)
	      {
              num1 = a;
	          num2 = b;	
	          next = NULL;
          }
}; //Node

void display(Node *head)    //Function to display - GIVEN
{
    cout << "\nTraverse and display linklist data" << endl;
    Node *current = head;
	while (current)
	{
        cout <<"|"<< current->num1 <<" "<< current->num2 <<"|"<<"\t" ;
        current = current->next;
    }
    cout << endl << endl;
} //display

int main()
{
	int counter = 0, f = 1;
	int s = 5; 
	
	//Code to insert 3 nodes - GIVEN  
    Node *head, *last;
	
	head = last = new Node(f, s);
           
	while (counter < 3)
	{
	    if (counter != 0)
	    {
	       f++;
	       s++;
	       last->next = new Node(f, s); 
	       last = last->next;
        }
	    counter++;
   }   

   display(head);   

   /////////////////////////////////////////////////////////////////////////////     
   //Task 1 : Write the code to calculate and display the sum of num1 value for 
   //         first and second node [4 marks]
   
   cout << "\nExecuting Task 1 - calculate the sum of num1 value for the first and "
   	 	<< "second node" << endl;
   
   int sum = 0;
   
   //Calculate the value of sum
   //Answer Task 1 start here  
   Node* currHead = head;  //you have to declare this one first
   int currIndex = 0;      //this one keep track on which node we are
   
   while (currNode && currIndex <= 1)  { //why 1? because node that we gonna use is node 1(position: 0) and node 2(position: 1) [1m]
   sum = sum + currNode->num1; //sum = num1 of currNode which is 1 + num1 of next currNode which is 2 [1m]
   currNode = currNode->next; //after sum the num1 from first node, move to next node [1m]
   currIndex++;  //keep track of the current node we are until the loop stop [1m]
  }
   
   cout << "\nSum of num1 value in first and second node is equal to: " << sum << endl;    
   //Task 1 end   
   /////////////////////////////////////////////////////////////////////////////     
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 2 : Write the code to add 3 to the num2 value in all the nodes in the 
   //         linklist [6 marks]
   
   cout << "\nExecuting Task 2 - add 3 to num2 value in all the nodes" << endl;
   
   //Answer Task 2 start here  
   currNode = head; //here, we are making the current node to become the head, after this we will point who is the currNode [1m]
   while (currNode) { //there's no condition, since we are applying this to all currNode that we will move to [1m]
   	currNode->num2 += 3; //while we at the current node, it will sum num2 from this node to number 3 [2m]
   	currNode = currNode->next; //here it will move to next node & repeat the loop, resulting the num2 from the next node(now as current node) to be add with number 3 [2m]
   }
   //Task 2 end
   /////////////////////////////////////////////////////////////////////////////     
   display(head);   
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 3 : Write the code to create a new node with data num1 = 5 and num2 = 12 
   //         and set it is as the new head [4 marks]

   cout << "\nExecuting Task 3 - add new node(5, 12) as new head" << endl;
   
   //Answer Task 3 start here  
   Node* newNode = new Node (5, 12); //set up newNode(new memory address) to add new node by reusing container new Node [2m]
   newNode->next = head; //this one set the added node to be the new head [1m]
   head = newNode; //this declare that the default head before is replace with the new node. Don't use currHead as we are starting fresh with this new head [1m]
   
   //Task 3 end   
   /////////////////////////////////////////////////////////////////////////////     
   display(head);
 
   /////////////////////////////////////////////////////////////////////////////     
   //Task 4 : Write the code to move the head to become the last node and then 
   //         set the second node as the new head [4 marks]

   cout << "\nExecuting Task 4 - set head to last and set second node as new head" << endl;
   
   //Answer Task 4 start here  
   currNode = head; //make the current node as the head
   Node*locateNode = head;  //a pointer is created to point to the first node, 
   currIndex = 0; //we will start the node from the start
   
   while (locateNode && currIndex <= 2) { //loop will happen 3 times 
   	locateNode = locateNode->next; //to move the node to another node position
   	currIndex++; //keep track of the current node
   }
   //we rearranging the node list here
   locateNode->next = currNode; //we do this (vice versa from above) to link the node at third position to node at first position
   head = currNode->next; //after we link them, the next node will be the head
   last = currNode; //while the current node will be the last
   currNode->next = NULL; //the next one after the current node will be null=nothing
   
   //Task 4 end
   /////////////////////////////////////////////////////////////////////////////     
   display(head);
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 5: Write the code to insert new node with data num1 = 4 and num2 = 11 
   //        before the last node [8 marks]
   cout << "\nExecuting Task 5 - insert new node(4, 11) before last node" << endl;
   
   //Answer Task 5 start here  
   currNode = head; //declare current head
   locateNode = head; //locate current head
   newNode = new Node(4, 11); //add new node
   currIndex = 0; //declare current position
   
   while (locateNode && currIndex <= 1) { //this will move 2 times
   	locateNode = locateNode->next; //the current position of the new node will move to the right of the next node
   	currIndex++; //keep track of node position
   }
   
   newNode->next = locateNode->next; //newNode points to the same next node that locateNode points to, making the newNode as the third node of the list
   locateNode->next = newNode; //the new node is inserted by making the node before it points to the new node
   //Task 5 end
   /////////////////////////////////////////////////////////////////////////////     
   display(head);
   
   /////////////////////////////////////////////////////////////////////////////     
   //Task 6: Write the code to delete the second node in the list [4 marks]
   cout << "\nExecuting Task 6 - delete the second node" << endl;
   
   //Answer Task 6 start here  
   currNode = head;
   locateNode = currNode->next;
   currNode->next = locateNode->next;
   delete locateNode;
   //Task 6 end	
   /////////////////////////////////////////////////////////////////////////////     
   
   display(head);	

   return 0;	
} //main
