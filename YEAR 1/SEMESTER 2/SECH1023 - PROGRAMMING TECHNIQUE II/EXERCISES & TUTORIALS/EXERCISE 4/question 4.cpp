//? EXERCISE 4: ASSOCIATION

// Programming Technique II

// Member 1's Name: DAMIYA AINA BINTI BASIR ABD SHAMMAD (A23CS0220)
// Member 2's Name: NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)

// Log the time(s) your pair programming sessions
//  Date         Time (From)    To       Duration (in minutes)
//  8 June 2024      8pm      8.30pm          30 minutes
//  9 June 2024     11am     11.30pm          30 minutes 

// Video link:
// https://drive.google.com/drive/folders/11eN1iY9BaY17XwpezG1WPj-zq9QdJDOc?usp=drive_link


#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Term {
private:
    int coef;
    int exp;

public:
    Term(int c = 0, int e = 0) : coef(c), exp(e) {}
    void set(int c, int e);
    int evaluate(int x) const;
    int exponent() const;
    int coefficient() const;
};

void Term::set(int c, int e) {
    coef = c;
    exp = e;
}

int Term::evaluate(int x) const {
    return coef * pow(x, exp);
}

int Term::exponent() const {
    return exp;
}

int Term::coefficient() const {
    return coef;
}

class Polynomial {
private:
    vector<Term> terms;

public:
    Polynomial() {}
    void input();
    int evaluate(int x) const;
    Term largestTerm() const;
    int degree() const;
};

void Polynomial::input() {
    int numTerms;
    cout << "Enter a polynomial:" << endl;
    cout << "How many terms? => ";
    cin >> numTerms;
    for (int i = 0; i < numTerms; i++) {
        int c, e;
        cout << "Enter term #" << (i + 1) << " (coef and exp) => ";
        cin >> c >> e;
        Term term(c, e);
        terms.push_back(term);
    }
}

int Polynomial::evaluate(int x) const {
    int result = 0;
    for (const Term& term : terms) {
        result += term.evaluate(x);
    }
    return result;
}

Term Polynomial::largestTerm() const {
    Term largest = terms[0];
    for (const Term& term : terms) {
        if (term.exponent() > largest.exponent()) {
            largest = term;
        }
    }
    return largest;
}

int Polynomial::degree() const {
    return largestTerm().exponent();
}

//----------------------------------------------------------------------------
int main() {
    cout << endl;

    Polynomial poly;
    poly.input();
    cout << "Degree of the polynomial: " << poly.degree() << endl;

    cout << " x  \t\tPolynomial value" << endl;
    cout << "----\t\t----------------" << endl;

    for (int x = 0; x <= 5; x++) {
        cout << x << "  \t\t" << poly.evaluate(x) << endl;
    }

    cout << endl;

    cout << "Press Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}
