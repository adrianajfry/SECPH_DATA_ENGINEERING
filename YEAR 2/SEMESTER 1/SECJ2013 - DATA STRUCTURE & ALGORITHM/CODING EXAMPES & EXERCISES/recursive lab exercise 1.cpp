// Lab 2 - SECJ2013 - 23241 (Lab2.cpp)
// Group Members:
// 1. ???
// 2. ???
// 3. ???

/*Question:
Compile and run the Lab2_Question.cpp source file. The output will be something like below:

1 - *
2 - **
3 - ***
4 - ****
5 - *****
6 - ******

1 3 5 = 9

Modify the current implementations of printStar, printNum, and totalOdd functions 
inside the Lab2.cpp so the solution is made by using recursive approach instead of 
using the standard for {...} loop control statement.*/

#include <iostream>
#include <string>

using namespace std;

//convert printStar to recursive function
void printStar(int n) {                    //void printStar(int n) {
     if (n > 0) {                          //    for (int i = 1; i <= n; i++) {
         cout << "*";                      //        cout << "*";
        printStar(n - 1);                  // [recursive call with n - 1]
    }                                      //    }
}                                          // }
    

//convert printNum to recursive function
void printNum(int n) {                      //void printNum(int n) {
     if (n > 0) {                           //     for (int i = 1; i <= n; i++) {
        printNum(n - 1);                    // [recursive call with n - 1]
         cout << n << " - ";                //         cout << i << " - ";
         printStar(n);                      //         printStar(i);
         cout << endl;                      //         cout << endl;
     }                                      //     }
}                                           // }


//convert totalOdd to recursive function
int totalOdd(int list[], int n) {           //int totalOdd(int list[], int n) {
    if (n <= 0) {                           //    int total = 0;
        return 0;                           //    for (int i = 0; i < n; i++) {
    } else {                                //         if (list[i] % 2 != 0) {
        int lastElement = list[n - 1];      //             cout << list[i] << " ";
        int sum = totalOdd(list, n - 1);    //             cout << list[i] << " ";
        if (lastElement % 2 != 0) {         //             cout << list[i] << " ";
            cout << lastElement << "";      //             total += list[i];
            sum += lastElement;             //         }
        }                                   //     }
        return sum;                         //     return total;
    }                                       // }                   
}                                           

// Main function
int main(int argc, char *argv[]) {
    printNum(6);

    cout << "\n\n";

    int num[6] = {0, 1, 2, 3, 4, 5};
    int result = totalOdd(num, 6);
    cout << "= " << result << endl;
    return 0;
}

