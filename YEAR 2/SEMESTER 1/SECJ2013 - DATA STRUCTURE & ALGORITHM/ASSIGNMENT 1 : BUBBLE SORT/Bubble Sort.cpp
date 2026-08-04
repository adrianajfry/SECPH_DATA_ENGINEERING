#include <iostream>
using namespace std;

void bubbleSort(int array[], int n, int &comparisons, int &swaps) {
    comparisons = 0, swaps = 0;       
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swaps++;
            }
        }
    }
}

int main() {
    int marks[] = {75, 95, 60, 88, 70};
    int n = sizeof(marks) / sizeof(marks[0]);
    int comparisons, swaps;

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    } cout << endl;

    bubbleSort(marks, n, comparisons, swaps);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;

    return 0;
}

