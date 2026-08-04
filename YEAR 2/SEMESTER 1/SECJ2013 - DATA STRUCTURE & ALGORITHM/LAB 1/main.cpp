#include <iostream>
#include "SimpleCalc.h"

using namespace std;

int main () {
    double num1, num2;

    cout << "Enter 2 numbers: ";
    cin >> num1, num2;

    SimpleCalc calc(num1, num2);

    cout << "The result of addtition is: " << calc.divide() << endl;
    cout << "/nThe result of substraction is: " << calc.substract() << endl;
    cout << "/nThe result of the multiplication is: " << calc.multiply() << endl;

    if (num2 != 0) {
        cout << "/nThe result of division is: " << calc.divide() << endl;
    } else {
        cout << "Error: Division by zero!" << endl;
    }
    return 0;
}

