#include <iostream>
#include <conio.h>
#include "Sphere.h"
using namespace std;

int main()
{
	Sphere unitSphere;         // invoke constructor without parameter, radius is 1.0
	Sphere mySphere(5.1);      // invoke constructor with parameter, radius is 5.1

	cout << "\nInformation for the first sphere : " << endl;
	unitSphere.displayStatistics();
	cout << "\nInformation for the second sphere : " << endl;
	mySphere.displayStatistics();

	mySphere.setRadius(4.2);   // resets radius to 4.2
	cout << "\nNew diameter for mysphere = " << mySphere.getDiameter() << endl;
	_getch();

	return 0;
}  // end main