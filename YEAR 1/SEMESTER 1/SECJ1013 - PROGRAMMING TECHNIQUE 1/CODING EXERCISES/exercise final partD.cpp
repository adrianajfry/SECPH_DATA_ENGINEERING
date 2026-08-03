#include <iostream>
#include <iomanip>
using namespace std;
int main () {
	double val = 10.345;
	cout << setprecision(5) << val << endl;
	cout << setprecision(4) << val << endl;
	cout << setprecision(3) << val << endl;
	cout << setprecision(2) << val << endl;
	cout << setprecision(1) << val << endl;
	cout << "Apa khabar \n Semua" << endl;
	cout << static_cast<int>(val)/2 << endl;
	cout << setw(6) << val*5 << endl;
	cout << showpoint << fixed << setw(8) << val << endl;
	return 0;
}
