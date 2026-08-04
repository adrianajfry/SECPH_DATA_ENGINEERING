#include <iostream>
#include <string>
using namespace std;

int powerOfTwo(int n) {
	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return n + powerOfTwo(n-1) + (n - 1);
	}
}

int main() {
	int v = powerOfTwo(2);
	int w = powerOfTwo(0);
	int x = powerOfTwo(4);
	int y = powerOfTwo(1);
	int z = powerOfTwo(8);
	
	cout << v << endl;
	cout << w << endl;
	cout << x << endl;
	cout << y << endl;
	cout << z << endl;
}
