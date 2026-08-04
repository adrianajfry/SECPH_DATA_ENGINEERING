#include <iostream> 
#include <conio.h> 
using namespace std;

int main() { 
int* p;            // int* is used to point at p = new int, int* p only to declare p as integer
 p = new int; 
 *p = 30; 
 cout << "Value of p is " << p << endl; 
 cout << "Address of p is " << &p << endl; 
 cout << "Value of i via *p is " << *p << endl;
 
 delete p; 
 p = NULL; 
 
 getch(); 
 return 0; 
}
