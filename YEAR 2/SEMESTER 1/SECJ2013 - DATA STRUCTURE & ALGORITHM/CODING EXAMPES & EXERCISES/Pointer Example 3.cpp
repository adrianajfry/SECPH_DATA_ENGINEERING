#include <iostream>
#include <conio.h> 
using namespace std;

int main() {
 int i = 10;                                             // Declare an integer variable 'i' and assign it the value 10
 cout << "Value of i is " << i << endl;
 cout << "Address of i is " << &i << endl;
 
 int *p;                                                // Declare an integer pointer 'p'
 p = &i;                                                // Referencing: 'p' now stores the address of 'i'
 cout << "Value of p is " << p << endl; 
 cout << "Address of p is " << &p << endl;
 cout << "Value of i via *p is " << *p << endl;
 
 cout << "Changing value p using pointer. . ." << endl; 
 *p = 20;                                               // Dereferencing and assignment: The value at the address 'p' is changed
 cout << "Value of i after *p = 20; is " << i << endl;  // Output: 20 (because 'i' was modified through 'p')
 
 getch(); 
 return 0;
}
