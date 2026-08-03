#include <iostream>
using namespace std;

const int employees = 5;

void getData(int [], int [][2]);
void calculatePayroll(int [], int [][2], double [], double []);
void displayLine();
void printData(int [], int [][2], int [], double [], double []);
double highestOvertime(int [], double []);

int main() {
    int empID[employees];
    int empRecord[employees][2];
    int regularPay[employees];
    double otPay[employees];
    double totalPay[employees];
    int highestempID;
    double highest = -999;

    cout << "Payroll Program\n";
    getData(empID, empRecord);
    calculatePayroll(regularPay, empRecord, otPay, totalPay);
    cout << "Payroll Final Report";
    displayLine();
    cout << "\nID \t\t HOURS \t\t RATE(RM) \t\t REGULAR PAY (RM) \t\t OVERTIME (RM) \t\t TOTAL (RM)";
    printData(empID, empRecord, regularPay, otPay, totalPay);
    highestempID = highestOvertime(empID, otPay);
    cout << "\nStaff " << highestempID << " has the highest pay overtime of RM " << highest << "." << endl;

    return 0;
}

void getData(int empID[], int empRecord[][2]) {
    for (int i = 0; i < employees; i++) {
        cout << "ID : ";
        cin >> empID[i];
        cout << "Hours worked : " ;
        cin >> empRecord[i][0];
        cout << "Rate of Pay (RM per hour) : ";
        cin >> empRecord[i][1];
    }
}

void calculatePayroll(int regularPay[], int empRecord[][2], double otPay[], double totalPay[]) {
    for (int i = 0; i < employees; i++) {
        regularPay[i] = empRecord[i][0] * empRecord[i][1];

        if (empRecord[i][0] > 40) {
            otPay[i] = (empRecord[i][0] - 40) * 1.5 * empRecord[i][1];
        } else {
            otPay[i] = 0;
        }

        totalPay[i] = regularPay[i] + otPay[i];
    }
}

void displayLine() {
    cout << "---------------------------------------------------------------------------------------------------------";
}

void printData(int empID[], int empRecord[][2], int regularPay[], double otPay[], double totalPay[]) {
    for (int i = 0; i < employees; i++) {
        cout << "\n" << empID[i] << "\t\t" << empRecord[i][0] << "\t\t" << empRecord[i][1] << "\t\t"
             << regularPay[i] << "\t\t" << otPay[i] << "\t\t" << totalPay[i];
    }
}

double highestOvertime(int empID[], double otPay[]) {
    int highestempID = -1;
    double highest = -999;

    for (int i = 0; i < employees; i++) {
        if (otPay[i] > highest) {
            highest = otPay[i];
            highestempID = empID[i];
        }
    }

    return highestempID;
}

