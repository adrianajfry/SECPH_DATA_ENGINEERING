// ? EXERCISE 2: CLASS AND OBJECT MANIPULATIONS

/// Programming Technique II

// Member 1's Name: DAMIYA AINA BINTI BASIR ABD SHAMMAD (A23CS0220)
// Member 2's Name: NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)
//
// Section: 03
// Member 1's Name: DAMIYA AINA BINTI BASIR ABD SHAMMAD (A23CS0220)    Location: JOHOR BAHRU (i.e. where are you currently located)
// Member 2's Name: NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)        Location: JOHOR BAHRU

// Log the time(s) your pair programming sessions
//  Date           Time (From)       To        Duration (in minutes)
//  23/04/2024       9.15PM        9.40PM           25 minutes
//  23/04/2024       9.45PM       10.15PM           30 minutes
//  23/04/2024      10.30PM       11.15PM           45 minutes
//  24/04/2024       9.45PM       10.15PM           30 minutes
//  24/04/2024      10.30PM       10.55PM           25 minutes
//  24/04/2024         11PM       11.55PM           55 minutes

// Video link:
// https://drive.google.com/drive/u/0/folders/1ZfQiALkBYxPZDkUg_CEc70FZ8DaIYZRn

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

#define MAX_SUBJECT_COUNT 10

using namespace std;

// Subject Class Definition
class Subject {
private:
    string name;
    string code;
    int score;
    int creditHour;

public:
    // Parameterized Constructor
    Subject(string subjectName = "", string subjectCode = "", int subjectScore = 0) {
        name = subjectName;
        code = subjectCode;
        score = subjectScore;
        creditHour = subjectCode.back() - '0'; // Extract credit hour from the last digit of the subject code
    }

    // Destructor
    ~Subject() {}

    // Accessor Methods
    string getName() const {
        return name;
    }

    string getCode() const {
        return code;
    }

    int getScore() const {
        return score;
    }

    int getCreditHour() const {
        return creditHour;
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

    // Print Subject Information
    void print() const {
        cout << left << setw(15) << getCode();
        cout << left << setw(30) << getName();
        cout << left << setw(10) << getCreditHour();
        cout << left << setw(10) << getScore();
        cout << left << setw(10) << determineGrade();
        cout << left << setw(10) << determineGradePoint();
        cout << left << setw(10) << determinePointEarned() << endl;
    }

    // Operator Overloading for Comparison
    bool operator<(const Subject& other) const {
        return this->getScore() < other.getScore();
    }
};

// Function to Read Subjects from User
void readSubjects(vector<Subject>& subjects, int numSubjects) {
    int subjectCount = 0;

    while (subjectCount < numSubjects && subjectCount < MAX_SUBJECT_COUNT) {
        string subjectCode, subjectName;
        int score;

        cout << "Enter info for subject #" << (subjectCount + 1) << ":" << endl;
        cout << "Subject Code => ";
        getline(cin, subjectCode);
        cout << "Subject Name => ";
        getline(cin, subjectName);
        cout << "Score Earned => ";
        cin >> score;

        // Handle invalid input for score
        if (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid score. Please enter a valid number." << endl;
            continue; // Skip to the next iteration to re-enter
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        subjects.emplace_back(subjectName, subjectCode, score);
        subjectCount++;
    }
}

// Find the Subject with the Lower Score
Subject findSmaller(const Subject& a, const Subject& b) {
    return (a < b) ? a : b;
}

// Main Function
int main() {
    int numSubjects;
    cout << "How many subjects do you want to enter? (max " << MAX_SUBJECT_COUNT << ") => ";
    cin >> numSubjects;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (numSubjects > MAX_SUBJECT_COUNT) {
        cout << "Cannot enter more than " << MAX_SUBJECT_COUNT << " subjects. Limiting to " << MAX_SUBJECT_COUNT << "." << endl;
        numSubjects = MAX_SUBJECT_COUNT;
    }

    // Initialize a Vector to Hold Subjects
    vector<Subject> subjects;
    subjects.reserve(MAX_SUBJECT_COUNT);

    // Read Subject Data from the User
    readSubjects(subjects, numSubjects);

    // Initialize Variables for Calculating Total Points and Credits
    double totalPoints = 0.0;
    double totalCredits = 0.0;

    // Output the Results Header
    cout << endl
         << endl
         << "THE RESULT"
         << endl
         << endl;

    cout << left << setw(15) << "Subject Code";
    cout << left << setw(30) << "Subject Name";
    cout << left << setw(10) << "Credit";
    cout << left << setw(10) << "Score";
    cout << left << setw(10) << "Grade";
    cout << left << setw(10) << "Point";
    cout << left << setw(10) << "Sub Total" << endl;
    cout << endl;

    // Loop Through the Subjects to Print and Calculate
    for (const auto& subject : subjects) {
        subject.print();
        totalPoints += subject.determinePointEarned();
        totalCredits += subject.getCreditHour();
    }

    // Calculate GPA
    double GPA = totalPoints / totalCredits;

    // Output the Final Totals and GPA
    cout << "\nTotal Point : " << totalPoints << endl;
    cout << "Total Credit : " << totalCredits << endl;
    cout << "GPA : " << fixed << setprecision(2) << GPA << endl;

    // Determine the Subject with the Lowest Score
    Subject lowestSubject = subjects[0];
    for (int i = 1; i < numSubjects; i++) {
        lowestSubject = findSmaller(lowestSubject, subjects[i]);
    }

    cout << "\n" << endl;
    cout << left << setw(15);
    cout << left << setw(30);
    cout << left << setw(10);
    cout << left << setw(10);
    cout << left << setw(10);
    cout << left << setw(10);
    cout << left << setw(10) << endl;
    cout << endl;

    cout << "LOWEST SUBJECT:\n" << endl;
    lowestSubject.print();
    
    // Keep Console Open to Prevent Auto-Exit
    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}
