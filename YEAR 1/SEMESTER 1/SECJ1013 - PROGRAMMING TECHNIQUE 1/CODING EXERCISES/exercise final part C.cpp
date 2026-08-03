#include <iostream>
#include <iomanip>
using namespace std;

int main () {
	double x = 15.674;
	double y = 235.73;
	double z = 9525.9874;
	
	cout << fixed << showpoint << setprecision(2);
	cout << x << endl << y << endl << z << endl;
	
	return 0;
}
