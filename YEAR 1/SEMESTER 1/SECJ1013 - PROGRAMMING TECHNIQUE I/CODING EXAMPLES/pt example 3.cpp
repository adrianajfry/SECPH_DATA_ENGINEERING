#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char word[6];  // Assuming a 5-letter word with one extra space for null character (\0)
    bool isPalindrome = true;

    cout << "Enter a 5 letter word: ";
    cin >> word; 

    // string length
    int length = strlen(word);

    // loop to test if word entered is a palindrome
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    cout << "The word " << word;
    if (isPalindrome) {
        cout << " is a palindrome." << endl;
    } else {
        cout << " is not a palindrome." << endl;
    }

    return 0;
}

