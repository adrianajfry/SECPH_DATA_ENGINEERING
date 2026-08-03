#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    vector<int> randomNumbers(100);

    for (int i = 0; i < 100; ++i) {
        randomNumbers[i] = rand() % 10;
    }

    int frequency[10] = {0};

    for (int i = 0; i < 100; ++i) {
        frequency[randomNumbers[i]]++;
    }

    cout << "Frequency of numbers from 0 to 9:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "Number " << i << ": " << frequency[i] << "\n";
    }

    return 0;
}


