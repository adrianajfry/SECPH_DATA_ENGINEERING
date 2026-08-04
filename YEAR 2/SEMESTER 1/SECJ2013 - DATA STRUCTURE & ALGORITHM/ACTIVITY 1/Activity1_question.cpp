#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// Function to check if a string contains only alphabetic characters (ignores spaces and punctuation)
bool isAlphaString(const string &str) {
    for (char c : str) {
        if (isalpha(c) == 0 && !isspace(c) && c != '.' && c != ',') { 
            return false;
        }
    }
    return true;
}

// Function to check if all alphabetic characters in a string are lowercase
bool isLowerString(const string &str) {
    for (char c : str) {
        if(isalpha(c) && !islower(c)) { 
            return false;
        }
    }
    return true;
}

int main() {
    // Step 1: Ask for group name
    string groupName;
    cout << "Enter your group name: ";
    getline(cin, groupName); 

    // Step 2: Open the input file for reading
    ifstream inputFile("input.txt"); 
    if (!inputFile) {
        cout << "Error opening input.txt" << endl;
        return 1;
    }

    // Step 3: Open the output file for writing
    ofstream outputFile("output.txt"); 
    if (!outputFile) {
        cout << "Error opening output.txt" << endl;
        return 1;
    }

    // Step 4: Write the group name to the output file
    outputFile << "Group Name: " << groupName << endl << endl; 

    // Step 5: Read the input file line by line and process it
    string line;
    while (getline(inputFile, line)) { 
        // Convert specific lines based on their content
        if (line.find("this line should be all capital letters") != string::npos) {
            for (char &c : line) {
                c = toupper(c); 
            }
        } else if (line.find("THIS LINE SHOULD BE ALL SMALL LETTERS") != string::npos) {
            for (char &c : line) {
                c = tolower(c); 
            }
        } else if (line.find("isalpha") != string::npos) {
            if (isAlphaString(line)) {
                line = "This line contains only alphabetic characters.";
            } else {
                line = "This line contains non-alphabetic characters.";
            }
        } else if (line.find("islower") != string::npos) {
            if (isLowerString(line)) {
                line = "All alphabetic characters in this line are lowercase.";
            } else {
                line = "Not all alphabetic characters in this line are lowercase.";
            }
        }

        // Write the processed line to the output file
        outputFile << line << endl; 
    }

    // Step 6: Close both files
    inputFile.close(); 
    outputFile.close(); 

    cout << "File processing complete. Check output.txt for results!" << endl;
    return 0;
}

