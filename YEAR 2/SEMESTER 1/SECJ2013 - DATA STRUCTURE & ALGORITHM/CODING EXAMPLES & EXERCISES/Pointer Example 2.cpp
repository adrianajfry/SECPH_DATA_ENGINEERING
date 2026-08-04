#include <iostream>
#include <conio.h> 
using namespace std;

int main() {
 int i = 10;
 cout << "Value of i is " << i << endl;
 cout << "Address of i is " << &i << endl;
 
 int *p;
 p = &i;
 cout << "Value of p is " << p << endl;
 cout << "Address of p is " << &p << endl;
  
 return 0;
}

