/* Question : Array stack implementation for Car ShowRoom Simulation   */

// Name : 
// Matric Num : 

# include<iostream>
#include<string>
const int SIZE=7;

using namespace std;

class CarStack
{
    int top;
    public:
    string car[7];  
    CarStack()
    {
        top = -1;
    }
    
    
    void push(string x);
    void pop();
    bool isEmpty();
    bool isFull();
    string stackTop();
    void display();
	int checkSize();   
};

void CarStack::push(string x)
{
    if(isFull())
    {
        cout << "CarStack Overflow \n";
    }
    else
    {
    	top++;
        car[top] = x;
    }
}

void CarStack::pop()
{
    if(isEmpty())
        cout << "CarStack Underflow \n";
    else
        top--;
}

bool CarStack::isEmpty()   
{
    if(top < 0)
    {
        return true;
    }
    else
    {
     return false;
    }
}
    

bool CarStack::isFull() 
{
    if(top >SIZE-1)
    {
        return true;
    }
    else
    {
     return false;
    }
}
    
    
//*Task 1 : stackTop implementation - 8M
//-------------------------------------------
string CarStack::stackTop () {
	if (isEmpty()) {
		string temp = "There is no car in the stack.";
		return temp;
	} else {
		string temp = car[top]; //string will show temporary car at Top 
		return temp;
	}
}


//*Task 2 : display implementation - 12M
//----------------------------------------------
void CarStack::display() {
	int temp = top; //marking last in as the top
	if (isEmpty()) {
		cout << "There is no car in the stack."; //no return temp; as this only display
	} else {
		while (temp != -1) { //the loop will repeat as long as the stack is not empty
			cout << car[temp] << endl; //display the car
			temp = temp - 1;  //since we start at the back of the array, it will minus until -1
		}
	}
}


//*Task 3 :   checkSize implementation 8M
//-------------------------------------------------    
int CarStack::checkSize () {
	int total, temp = top; //marking last in as the top
	if (isEmpty()) {
		return 0; //why return instead of cout just like above? Cuz this function as for the size to be display (not display all only)
	} else if (isFull()) {
		return 7; //return the size of array
	} else {
		while (temp != -1) {
			total++;  //total of array size, not array position
			temp = temp - 1; //since we start at the back of the array, it will minus until -1
		}
	}
}

// main function
int main() {

    CarStack s1;
    string theCars[7]={"Estima","Alphard","Velphire","Mazda","Nissan","Shilpy","Vios"};
    
     /*
        perform the operation that represent the output in the question 
    */
    
    //*Task 4 - in main function 
    //----------------------------------------------------------------------
    
	// i) Use the appropriate code that able to push theCars elements into the stack. 
	   // Display all the elements  - 8M 
	   cout << "Question i" << endl;
	   for(int i= 0; i < 7; i++) { //will stop display until reach 7 (0, 1, 2, 3, 4, 5, 6)
	   	s1.push(theCars[i]);  //push out the car from stack to display 
	   } s1.display();	
       
   
    //ii) Use the appropriate code that able to remove and display the removed  
	     // 2 top elements in the stack - 6M
	     cout << endl << "Question ii" << endl;
	     cout << "Remove " << s1.stackTop() << endl;
	     s1.pop();
	     
	     cout << "Remove " << s1.stackTop() << endl;
	     s1.pop();
	
   
    //iii) Display all the elements in the stack.
		// Use the appropriate code that able to display the number of elements in the stack - //8M
	cout << endl << "Question iii" << endl;
	s1.display();
	cout << "#Cars in Showroom : " << s1.checkSize();
   //-------------------------------------------------------------------------------------------
   return 0;
}
