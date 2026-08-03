// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II

// Member 1's Name: DAMIYA AINA BINTI BASIR ABD SHAMMAD (A23CS0220)
// Member 2's Name: NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)
//
// Section: 03
// Member 1's Name: DAMIYA AINA BINTI BASIR ABD SHAMMAD (A23CS0220) Location: KOTA BHARU, KELANTAN (i.e. where are you currently located)
// Member 2's Name: NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)   Location: KUALA LUMPUR

// Log the time(s) your pair programming sessions
//  Date         Time (From)   To             Duration (in minutes)
//  13/4/2024     10.15PM      12.30AM        135 MINUTES   
//  14/4/2024     11.15PM      12.30AM        75 MINUTES
//  15/4/2024      4.15PM       5.30AM        135 MINUTES  

// Video link:
// https://drive.google.com/drive/folders/1nvbEvUYzLxE1bXUqhxBiJ27ty182UeqU?usp=sharing


#include <iostream>
#include <string>

using namespace std;

class Subject {
private:
    string name;
    string code;
    int score;
    int creditHour;

public:
    // Parameterized constructor
    Subject(string subjectName = "", string subjectCode = "", int subjectScore = 0) {
        name = subjectName;
        code = subjectCode;
        score = subjectScore;
        creditHour = subjectCode.back() - '0'; // Get credit hour from the last digit of code
    }

    // Destructor
    ~Subject() {}

    // Accessors
    string getName() const {
        return name;
    }

    string getCode() const {
        return code;
    }

    int getScore() const {
        return score;
    }

    // Mutators
    void setName(string subjectName) {
        name = subjectName;
    }

    void setCode(string subjectCode) {
        code = subjectCode;
        creditHour = subjectCode.back() - '0'; // Update credit hour when code changes
    }

    void setScore(int subjectScore) {
        score = subjectScore;
    }

    // Other accessor methods
    string determineGrade() const {
        if (score >= 90) 
            return "A+";
        else if (score >= 80)
            return "A";
        else if (score >= 75) 
            return "A-";
        else if (score >= 70)
            return "B+";
        else if (score >= 65)
            return "B";
        else if (score >= 60)
            return "B-";
        else if (score >= 55)
            return "C+";
        else if (score >= 50)
            return "C";
        else if (score >= 45)
            return "C-";
        else if (score >= 40)
            return "D+";
        else if (score >= 35)
            return "D";
        else if (score >= 30)
            return "D-";
        else
            return "E";
    }

    double determineGradePoint() const {
        string grade = determineGrade();
        if (grade == "A+")
            return 4.00;
        else if (grade == "A")
            return 4.00;
        else if (grade == "A-")
            return 3.67;
        else if (grade == "B+")
            return 3.33;
        else if (grade == "B")
            return 3.00;
        else if (grade == "B-")
            return 2.67;
        else if (grade == "C+")
            return 2.33;
        else if (grade == "C")
            return 2.00;
        else if (grade == "C-")
            return 1.67;
        else if (grade == "D+")
            return 1.33;
        else if (grade == "D")
            return 1.00;
        else
            return 0.00;
    }

    double determinePointEarned() const {
        return creditHour * determineGradePoint();
    }

    int getCreditHour() const {
        return creditHour;
    }
};

int main() {
    string subjectName, subjectCode;
    int score;

    cout << "Enter the following data:" << endl;
    cout << "Subject name => ";
    getline(cin, subjectName);
    cout << "Subject code => ";
    getline(cin, subjectCode);
    cout << "Score earned => ";
    cin >> score;

    Subject subject(subjectName, subjectCode, score);

    cout << endl << "THE RESULT" << endl << endl;
    cout << "Subject Code : " << subject.getCode() << endl;
    cout << "Subject Name : " << subject.getName() << endl;
    cout << "Credit Hour  : " << subject.getCreditHour() << endl;
    cout << "Score Earned : " << subject.getScore() << endl;
    cout << "Grade Earned : " << subject.determineGrade() << endl;
    cout << "Grade Point  : " << subject.determineGradePoint() << endl;
    cout << "Point Earned : " << subject.determinePointEarned() << endl;

    return 0;
}