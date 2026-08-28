#include <iostream>
using namespace std;
int main () {
	int i;
	string students[] = {"Ali", "Chong", "Muthu", "Salmah"};
	int midTestMark[] = {75, 80, 81, 88};
	
	for (i = 0; i < 4; i++ ) {
		cout << students[i] << "\t" << midTestMark[i] << endl;
	}
	
	return 0;
}
