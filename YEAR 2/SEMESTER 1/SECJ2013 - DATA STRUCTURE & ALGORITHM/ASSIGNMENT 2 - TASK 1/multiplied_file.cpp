#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main () {
	string input_file_path = "input.txt";
	string output_file_path = "output.txt";
	
	int multiplier = 5;
	
	ifstream input_file(input_file_path.c_str());
	if (!input_file) {
		cerr << "Error opening input file" << endl;
		return 1;
	}
	
	vector<int> numbers;
	int number;
	while (input_file >> number) {
		numbers.push_back(number);
	} 
	input_file.close();
	
	for (int i = 0; i < numbers.size(); ++i) {
		numbers[i] *= multiplier;
	}
	
	ofstream output_file(output_file_path.c_str());
	if (!output_file) {
		cerr << "Error opening output file" << endl;
		return 1;
	}
	
	for (int i = 0; i < numbers.size(); ++i) {
		output_file << numbers[i] << " ";
	}
	output_file.close();
	
	cout << "Multiplied numbers have been saved to " << output_file_path << endl;
	return 0;
}
