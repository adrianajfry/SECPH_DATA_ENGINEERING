#include <iostream>
#include <string>
using namespace std;

int sumUpTo(int n) {
	if (n <= 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return n + sumUpTo(n-1);
	}
}

int main() {
	int c;
	c = sumUpTo(5);
	cout << c << endl;
	return 0;
}
