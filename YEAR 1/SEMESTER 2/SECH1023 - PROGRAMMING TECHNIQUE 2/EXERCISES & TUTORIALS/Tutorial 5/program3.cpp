#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
    string expression;
	string operand1, operand2, operation;
    double value1, value2, result;
    
    // Task 1: Read the string of arithmetic expression and put it into the variable "expression"
	cout <<"Enter an arithmetic expression, e.g. 20 + 30  => ";
	getline(cin, expression);
	
    
    // Task 2: Extract the operator and both operands from "expression" and 
	//           put them into the variables "operation", "operand1", and "operand2", accordingly
		
    size_t spacePos = expression.find(' ');
    operand1 = expression.substr(0, spacePos);

    size_t spacePos2 = expression.find(' ', spacePos + 1);
    operation = expression.substr(spacePos + 1, spacePos2 - spacePos - 1);
    
    operand2 = expression.substr(spacePos2 + 1);

    
	// Task 3:  Convert the string operands to numbers. 
	//            Put the numbers into variables "value1" and "value2", respectively
	
	value1 = stod(operand1);
    value2 = stod(operand2);

    
    // Task 4: Determine the type of operation (i.e., either +, -, *, or / ) and perform the arithmetic calculation accordingly.
    //          Put the result of the calculation into the variable "result".
   if (operation == "+") {
    result = value1 + value2;
   } else if (operation == "-") {
    result = value1 - value2;
   } else if (operation == "x" || operation == "X") {
    result =  value1 * value2;
   } else if (operation == "/") {
    result = value1 / value2;
   } else {
    cout << "Error: Division by zero is not allowed!";
    return 1;
   }
		
    cout << "The value of the expression " << expression << " is " << result << endl << endl;
    
     cout << "Press any key to exit...";
    cin.get(); 
}

